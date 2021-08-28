#
# Copyright (C) The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.4.1)

# build native_app_glue as a static lib
set(${CMAKE_C_FLAGS}, "${CMAKE_C_FLAGS}")
add_library(native_app_glue STATIC
    ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# now build app's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")

######         libusb         ######
set(LIBUSB_DIR ${CMAKE_SOURCE_DIR}/libusb)
set(LIBUSB_SOURCES ${LIBUSB_DIR}/libusb/core.c
        ${LIBUSB_DIR}/libusb/descriptor.c
        ${LIBUSB_DIR}/libusb/hotplug.c
        ${LIBUSB_DIR}/libusb/io.c
        ${LIBUSB_DIR}/libusb/sync.c
        ${LIBUSB_DIR}/libusb/strerror.c
        ${LIBUSB_DIR}/libusb/os/linux_usbfs.c
        ${LIBUSB_DIR}/libusb/os/events_posix.c
        ${LIBUSB_DIR}/libusb/os/threads_posix.c
        ${LIBUSB_DIR}/libusb/os/linux_netlink.c
        ${LIBUSB_DIR}/libusb/os/linux_android_jni.c
        )

include_directories(${LIBUSB_DIR}
        ${LIBUSB_DIR}/android
        ${LIBUSB_DIR}/libusb
        ${LIBUSB_DIR}/libusb/os
        )

add_library(libusb STATIC ${LIBUSB_SOURCES})

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS
    "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

add_library(libusbNativeAndroidTest SHARED main.cpp)

target_include_directories(libusbNativeAndroidTest PRIVATE
    ${ANDROID_NDK}/sources/android/native_app_glue)

# add lib dependencies
target_link_libraries(libusbNativeAndroidTest
        android
        libusb
        native_app_glue
        EGL
        GLESv1_CM
        log)
