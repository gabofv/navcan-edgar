# navcan-edgar
NavCan, a km countdown device with a beeper that can be connected to any car that exposes an OBD2 port. Used to indicate when the driver should take their next detour after setting the km count via the rotary encoder. Customer: a friend.

## Table of Contents

1. Hardware / Components
2. Software
3. Methodology
    1. Design
    2. Prototyping
    3. PCB Design
    4. Manufacture
4. Design Choices
5. Conclusion

## 1. Hardware / Components 
Note: format is "Description | DigiKey Part # | Manufacturer"
### MCU
- STM32L432KCU6 | 497-16578-ND | STMicroelectronics
### 7-Segment Display
- Display LED 7-Seg | 1568-11405-ND | SparkFun Electronics
- IC Driver 7-Seg 4-Digit QSOP-16 | MAX6958AAEE+-ND | Analog Devices Inc./Maxim Integrated
### Rotary Encoder
- Rotary Encoder Mechanical (Active) | PEC11R-4215K-S0024-ND | Bourns Inc.
- IC Schmitt Trigger US8 (Non-Inv) | NC7NZ17K8XCT-ND | onsemi
### Buzzer
- Buzzer Piezo 12V | 433-1065-ND | Soberton Inc.
### Adapters
- QSOP-16 to DIP-16 | PA0028-ND | Chip Quik Inc.
- UMAX-8/USOP-8/MSOP-8 to DIP-8 | PA0026-ND | Chip Quik Inc.
## 2. Software
- IDE: STM32CubeIDE
- Programming Language: C
- CAD: EasyEDA
