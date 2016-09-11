//by Kiona Hagen Niehaus, 01.09.2016, version 1. 

/* Part of Assembling Desire; this version shown in Metasis 2016 at Goldsmiths, University of London. 

This program receives capactive touch data from Arduino, and sends that data via OSC and a closed wifi network
to openFrameworks on nine Raspberry Pis. This program also displays the touch and the release data for the pins on the 
wearable conductive suit worn by the artist, for troubleshooting and design purposes. 

*/

//libraries
import processing.serial.*;
import oscP5.*;
import netP5.*;

Serial mPort; //variable for the serial port where the program is listening for data 
OscP5 oscSend; //OSC sender variable to send to oF
NetAddress loc1, loc2, loc3, loc4, loc5, loc6, loc7, loc8, loc9; //Different address location for individual Pis

int touch; //int variable for the numbered section of the suit (pin) that has been touched
int release; //int variable for the numbered section of the suit (pin) that has been released

void setup(){
  
  size(300, 300); //small square for displaying data ints
  frameRate(100); //updates display a little faster
  
  mPort = new Serial(this, Serial.list() [1], 9600); //serial port, choose the serial port I need from the array of available, set baud rate to 9600 so Arduino and Processing can talk
  mPort.clear(); //flush serial buffer 
  mPort.bufferUntil('\n'); //reset buffer on return 
  
  oscSend = new OscP5 (this, 12435); //define OSC port, number must be consistent with that declared in .h file of oF project 
  
  /*Here I declare the individual IP addresses to send the OSC data to. If this system were much larger or otherwise more complex,
  I would have used an alternate method for storing the IP addresses and iterating through them. However, because this system is 
  small and having access to the IPs in the code was useful for debugging while setting static IPs for all the Pis, creating a 
  separate way of handling the addresses felt like it would be making my code unnecessarily complex and counterproductive to my
  needs in this setting. */
  
  loc1 = new NetAddress("192.168.0.101", 12435); //static Pi IP, corresponds to receiver adRec-1
  loc2 = new NetAddress("192.168.0.103", 12435); //static Pi IP, corresponds to receiver adRec-2
  loc3 = new NetAddress("192.168.0.100", 12435); //static Pi IP, corresponds to receiver adRec-3
  loc4 = new NetAddress("192.168.0.102", 12435); //static Pi IP, corresponds to receiver adRec-4
  loc5 = new NetAddress("192.168.0.104", 12435); //static Pi IP, corresponds to receiver adRec-5
  loc6 = new NetAddress("192.168.0.105", 12435); //static Pi IP, corresponds to receiver adRec-6
  loc7 = new NetAddress("192.168.0.106", 12435); //static Pi IP, corresponds to receiver adRec-7
  loc8 = new NetAddress("192.168.0.107", 12435); //static Pi IP, corresponds to receiver adRec-8
  loc9 = new NetAddress("192.168.0.108", 12435); //static Pi IP, corresponds to receiver adRec-9
  
  }

void draw(){
  
  background(100, 10, 20); // set the background to a nice red color 
  
  noStroke(); //no outline
  fill(255); //white text
  text(touch + " touched", 120, 100); //display 'touched' pin data from Arduino
  text(release + " released", 120, 200); //display 'released' pin data from Arduino
  
  
}