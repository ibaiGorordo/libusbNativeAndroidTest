# libusbAndroidTest
 Example of a Native Android app for testing the libusb library in Android.
 
# Why
Support for libusb in non rooted Android devices is still not properly solved [ref](https://github.com/libusb/libusb/pull/874), this repository tries combines the code from various repositories (references below) to generate a Native Android app to connect to usb devices.

# Usage
The modified libusb library is added as a submodule, so you will have to load the submodule either by clonning with the recursive flag or:

```
git clone https://github.com/ibaiGorordo/libusbAndroidTest.git
git submodule update --init
```


# Output
Nothing will appear on the screen, you will have to check the logcat and filter for text contanining the **LOG_TAG** string (defined in libusb_utils.h and set to *libusbAndroidTest* by default).

Example
```
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:   Manufacturer:              Movidius Ltd.
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:   Product:                   Movidius MyriadX
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:   Serial Number:             03e72485
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:   Configuration:
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:     wTotalLength:            32
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:     bNumInterfaces:          1
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:     bConfigurationValue:     1
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:     iConfiguration:          0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:     bmAttributes:            80h
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:     MaxPower:                250
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:     Interface:
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       bInterfaceNumber:      0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       bAlternateSetting:     0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       bNumEndpoints:         2
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       bInterfaceClass:       255
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       bInterfaceSubClass:    17
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       bInterfaceProtocol:    255
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       iInterface:            0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       Endpoint:
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bEndpointAddress:    81h
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bmAttributes:        02h
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         wMaxPacketSize:      512
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bInterval:           0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bRefresh:            0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bSynchAddress:       0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:       Endpoint:
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bEndpointAddress:    01h
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bmAttributes:        02h
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         wMaxPacketSize:      512
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bInterval:           0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bRefresh:            0
2021-08-27 21:12:22.838 4615-5852/com.example.native_activity I/libusbAndroidTest1:         bSynchAddress:       0
```

# References:
- Pull request to improve the use of libusb in Android: https://github.com/libusb/libusb/pull/874
- Repository with the corrections in the libusb library used in this repository: https://github.com/xloem/libusb/tree/android
- Repository where the libusb_utils.h functions were taken from: https://github.com/Peter-St/libusb


