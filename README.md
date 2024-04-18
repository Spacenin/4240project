# Instructions
## Hardware
This project utilizes the MSP-EXP430FR5994 development board, CC1101 radio, and ADXL345 accelerometer. The parts can be found at the following links:
- ADXL: https://learn.sparkfun.com/tutorials/adxl345-hookup-guide/all
- CC1101: https://www.ti.com/product/CC1101
- MSP-EXP430FR5994: https://www.ti.com/tool/MSP-EXP430FR5994

Wiring for the transmitter and receiver can be found in the hardware code, under their respective folders. These were developed with the Energia MSP430 IDE, found at https://energia.nu/.

## Software
### Sensor
The transmitter/receiver code are listed in their respective folders, as transmitter/receiver.ino. These can both be compiled and uploaded via Energia.
Serial monitoring and data logging can be done via the Energia serial monitor, on the attached receiver node.

### Command Line Tool
The command line tool utilizes Python to run the various scripts, therefore it is a depedency. The first script, extractlower.py, generates a series of random seeding data utilizing the low ordered
bits from each data entry in the specified input file as &lt;python extractlower.py _inputfile_&gt;. Within the repo are two .log files which can be used as examples. The second script, randgen.py, generates _n_ number of random numbers 
using the generator seeded from before. Command line options for this script can be seen below:

![image](https://github.com/Spacenin/4240project/assets/22013445/d99fce11-217f-40f4-8200-d25dd6bfe890)
