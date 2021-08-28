#include <android_native_app_glue.h>
#include "libusb_utils.h"

// outputs logs to show libusb's new thread is detached when closed
JavaVM * _vm;
jint AttachCurrentThreadProxy(JavaVM* vm, JNIEnv** envptr, void* args)
{
  jint ret = _vm->functions->AttachCurrentThread(_vm, envptr, args);
  log("AttachCurrentThreadProxy: %i", ret);
  return ret;
}

jint DetachCurrentThreadProxy(JavaVM* vm)
{
  jint ret = _vm->functions->DetachCurrentThread(_vm);
  log("DetachCurrentThreadProxy: %i", ret);
  return ret;
}

jint GetEnvProxy(JavaVM* vm, void**envptr, jint arg)
{
  jint ret = _vm->functions->GetEnv(_vm, envptr, arg);
  log("GetEnvProxy: %i", ret);
  return ret;
}
JNIInvokeInterface _vm_proxy = {
        .AttachCurrentThread = AttachCurrentThreadProxy,
        .DetachCurrentThread = DetachCurrentThreadProxy,
        .GetEnv = GetEnvProxy,
};
JavaVM *vm_proxy = (JavaVM*)&_vm_proxy;


void android_main(struct android_app * state) {
  libusb_context * ctx;
  int r;

  // back proxy
  _vm = state->activity->vm;

  // libusb
  r = libusb_set_option(nullptr, LIBUSB_OPTION_ANDROID_JAVAVM, &vm_proxy/*state->activity->vm*/, 0);
  log("libusb_set_option ANDROID_JAVAVM: %s", libusb_strerror(r));

  r = libusb_init(&ctx);

  libusb_device ** list;
  r = libusb_get_device_list(ctx, &list);
  log("libusb_get_device_list: %s", libusb_strerror(r > 0 ? LIBUSB_SUCCESS : r));

  for (int i = 0; i < r; ++ i) {
    libusb_device *dev = list[i];
    struct libusb_device_descriptor desc{};
    libusb_device_handle *dev_handle;

    r = libusb_get_device_descriptor(dev, &desc);

    r = libusb_open(dev, &dev_handle);
    log("libusb_open: %s", libusb_strerror(r));

    if (r == LIBUSB_SUCCESS) {

      // Work with the device
      print_device(dev, dev_handle);



      // Close the device
      libusb_close(dev_handle);
    }
  }

  libusb_free_device_list(list, 1);
  libusb_exit(ctx);
}