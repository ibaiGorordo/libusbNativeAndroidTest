# libusbAndroidTest
 Example of a Native Android app for testing the libusb library in Android.
 
# Why
Support for libusb in non rooted Android devices is still not properly solved [ref](https://github.com/libusb/libusb/pull/874), this repository tries combines the code from various repositories (references below) to generate a Native Android app to connect to usb devices.

# Usage
The modified libusb library is added as a submodule, so you will have to load the submodule either by clonning with the recursive flag or:

```
git clone https://github.com/ibaiGorordo/libusbAndroidTest.git
cd libusbAndroidTest
git submodule update --init
```

# Output
Nothing will appear on the screen, you will have to check the logcat and filter for text contanining the **LOG_TAG** string (defined in libusb_utils.h and set to *libusbAndroidTest* by default).

### Example
```
I/libusbAndroidTest:  
Dev (bus 1, device 2): 03E7 - 2485 speed: Unknown
      Manufacturer:              Movidius Ltd.
      Product:                   Movidius MyriadX
      Serial Number:             03e72485
      Configuration:
        wTotalLength:            32
        bNumInterfaces:          1
        bConfigurationValue:     1
        iConfiguration:          0
        bmAttributes:            80h
        MaxPower:                250
        Interface:
          bInterfaceNumber:      0
          bAlternateSetting:     0
          bNumEndpoints:         2
          bInterfaceClass:       255
          bInterfaceSubClass:    17
          bInterfaceProtocol:    255
          iInterface:            0
          Endpoint:
            bEndpointAddress:    81h
            bmAttributes:        02h
            wMaxPacketSize:      512
            bInterval:           0
            bRefresh:            0
            bSynchAddress:       0
          Endpoint:
            bEndpointAddress:    01h
            bmAttributes:        02h
            wMaxPacketSize:      512
            bInterval:           0
            bRefresh:            0
            bSynchAddress:       0
```

# References:
- Pull request to improve the use of libusb in Android: https://github.com/libusb/libusb/pull/874
- Repository with the corrections in the libusb library used in this repository: https://github.com/xloem/libusb/tree/android
- Repository where the libusb_utils.h functions were taken from: https://github.com/Peter-St/libusb


