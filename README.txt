Assembling Desire, Kiona Hagen Niehaus, 01 September 2016. 

This project is a final project for the MFA in Computational Arts, Goldsmiths, University of London. 

Platform requirements: OS X (10.6 or above), Processing and Arduino.
Also required: Nine Raspberry Pis, model 2 B or 3 B, with openFrameworks installed. Router (no internet connection needed). 

Raspberry Pi openFrameworks (oF) add ons: ofxOsc, ofxOMXPlayer.

Libraries (Processing): oscP5, netP5, serial 

Libraries (Arduino): MPR121 (Adafruit)

Other hardware: Arduino Uno, MPR121 capacitive touch sensing chip

The Arduino code came from the Adafruit test example (https://github.com/adafruit/Adafruit_MPR121); I have added a sender to Processing for the data used in this project.   

Instructions: 

Within Id-Me folder:

Move “MPR121suitSender” folder to your Documents/Arduino folder
Move “adSuitTouchRec” folder to your Documents/Processing folder
Move “adRec-x” folders to your oF/apps/myApps folder one each individual Raspberry Pi
**Please note that adRec-1, -6, and -7 are currently set to run on a Pi 2 Model B, and all others are to run on a Pi 3 Model B. This can be changed by copying the SRC folder, add ons and any relevant media into these folders in a new project.**

1. Upload Arduino sketch to board. The chip should be connected as illustrated here (https://learn.sparkfun.com/tutorials/mpr121-hookup-guide), and any conductive material should be connected to the chip. Close Arduino once you have uploaded the sketch. 

2. Make sure your router is on and your network is active. 

3. Turn on all Raspberry Pis and have oF running. 

3. Connect Arduino and chip via USB. Open and run the Processing sketch. If no values appear when the material has been touched, repeat these instructions or check your hardware connections. 

All video and photos ©Kiona Hagen Niehaus 2016. Do not use or reproduce without permission. 

Contact: knieh001@gold.ac.uk 







