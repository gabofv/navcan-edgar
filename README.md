# navcan-edgar
NavCan, a km countdown device with a beeper that can be connected to any car that exposes an OBD2 port. Used to indicate when the driver should take their next detour after setting the km count via the rotary encoder.

## Table of Contents

1. Hardware / Components
2. Software
3. Methodology
    1. Design
    2. Prototyping
    3. PCB Design
    4. Manufacture & Final Product
4. Design Choices
5. Conclusion
6. Appendix

## 1. Hardware / Components 
<ins>Note:</ins> format is "Description | DigiKey Part # | Manufacturer"
### MCU
- STM32L432KCU6 | 497-16578-ND | STMicroelectronics
### 7-Segment Display
- Display LED 7-Seg | 1568-11405-ND | SparkFun Electronics
- IC Driver 7-Seg 4-Digit QSOP-16 | MAX6958AAEE+-ND | Analog Devices Inc./Maxim Integrated
### Rotary Encoder
- Rotary Encoder Mechanical (Active) | PEC11R-4215K-S0024-ND | Bourns Inc.
### Buzzer
- Buzzer Piezo 12V | 433-1065-ND | Soberton Inc.
### Adapters (Prototyping)
- QSOP-16 to DIP-16 | PA0028-ND | Chip Quik Inc.
- UMAX-8/USOP-8/MSOP-8 to DIP-8 | PA0026-ND | Chip Quik Inc.
### Other
- Resistor (1kΩ, ±5%) | - | -
- NPN Transistor (40V) | 2N4401 | -

## 2. Software
- IDE: STM32CubeIDE
- Programming Language: C
- CAD: Altium Designer

## 3. Methodology

### i. Design
tbd

### ii. Prototyping

#### Piezo Buzzer
Since the piezo buzzer used has an operating voltage of 3 ~ 16V, I tried three different configurations: 3.3V, 5V, and 12V. The MCU provided 3.3V and 5V, and a barrel jack power supply was used for 12V. Note that the buzzer's volume is directly proportional to the input voltage. The input voltage of 3.3V was chosen as the most reasonable one, as seen below (the multimeter can't read an exact 3.3V because the code toggles the pin quickly).

<img src="https://github.com/user-attachments/assets/348db6f6-cc48-43f3-89b8-f1590151e904"  width=300 /> &nbsp;

See Figure XXXX in the Appendix for the circuit used to test for 5V and 12V, which used the pin signal and a 1kΩ resistor to control a BJT (NPN transistor), which acted as a switch.

### iii. PCB Design
tbd

### iv. Manufacture & Final Product
tbd

## 4. Design Choices
tbd

## 5. Conclusion
tbd

## 6. Appendix
<img src="https://github.com/user-attachments/assets/60faf31f-44a6-4006-8db8-2bcf31b29c9b" width=300 />
<img src="https://github.com/user-attachments/assets/66784fb1-c058-4210-9e39-dc255749a856" width=300 />
<img src="https://github.com/user-attachments/assets/041ba898-efcb-4215-9cc9-646393116a7a" width=450 />

