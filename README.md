# Arduino Ducky

### Requirement list:
* Arduino UNO R3
* OS (We recommend linux)
* [Arduino-keyboard-0.3.hex](http://web.archive.org/web/20140211100537if_/http://hunt.net.nz/sandbox/users/darran/weblog/b3029/attachments/03237/Arduino-keyboard-0.3.hex?sessionID=19d16b2670d01e17bbe4615aa9f04d186ba6995c)
* [Arduino-usbserial-uno.hex](https://roboticsclub.org/redmine/projects/quadrotor/repository/revisions/master/raw/arduino-1.0/hardware/arduino/firmwares/Arduino-COMBINED-dfu-usbserial-atmega16u2-Uno-Rev3.hex) (beware of CRLF and LF if using different OS)

### Prerequisites
    sudo apt install dfu-programmer

### Setting up guide:
[Enter DFU mode on Arudino UNO](https://www.arduino.cc/en/Hacking/DFUProgramming8U2)

    Windows might not be able to recognize the device in DFU mode so try Linux if the following commands doesn't work (if it says `no device present`)

Flash original Arduino UNO Firmware

    sudo dfu-programmer atmega16u2 erase
    sudo dfu-programmer atmega16u2 flash 'Arduino-usbserial-uno.hex' --suppress-bootloader-mem (this argument may be needed)
    sudo dfu-programmer atmega16u2 reset

Upload ArduinoDucky.ino to your arduino (the payload)
    
    Might need to reconnect the Arduino to the system if it is not recognized

Flash Arduino Keyboard Firmware

    sudo dfu-programmer atmega16u2 erase
    sudo dfu-programmer atmega16u2 flash 'Arduino-keyboard-0.3.hex'
    sudo dfu-programmer atmega16u2 reset

### Code Guide
[Key Values](https://github.com/coopermaa/USBKeyboard/blob/master/hid_keys.h)

Press key

    keyPress(0, <Keycode>); 

Example

    keyPress(LEFT_GUI, 0x15); // Press R Key

Press Multiple key

    keyPress(<Modifier Key>, <KeyCode>);

Example

    keyPress(LEFT_GUI, 0x15); // Press Windows Key + R

Release Key

    keyRelease();

Write Text

    keyString(<Text>);

Example

    keyString("Hello World!"); // Write Hello World
