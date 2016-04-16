# BB8_Body
Motor and central control unit for BB8 robot.

Work in progress...

Quick notes on this project:

Main Board
- Built on the PIC32 UBW32 "Bit Whacker" platform
- Requires Microchip Legacy Stack for USB drivers
- Memory allocation is setup to use USB bootloader
- Implements MPU-9150 9 DOF driver

BB-8 Audio:
- Built on XGS 16-bit PIC development board
- Custom wav audio trigger board software
- Streams wav files from an SD card
- Controlled via UART commands


Top Board:
- Arduino Nano
- Communicates with main board via I2C
- Controls body sphere LEDs (Neopixels)
- Functions as EEPROM storage for main board

Requires:
- MPLABX IDE v1.95 or greater
- Microchip legacy library TCP/IP and USB libraries
- MPLAB XC32 Compiler v1.20
- Arduino IDE

TODO: Detailed documentation and link to writeup
