void serialEvent(Serial mPort){
  
  String tData = mPort.readStringUntil('\n'); // string of data read, sent from Arduino 
  tData = trim(tData); //return, cut off any extra information
  
  OscMessage tMessage = new OscMessage ("/touch"); //osc message to be sent with touch data
  
  if (tData.charAt(0) == 'T'){ // if current touch data is marked 'T', received from Arduino 
    
    tData = tData.substring(1); //substring of data string for touch
    
    touch = int(tData); // value of 'touch' variable equals touch data 'T' received, int
    
    tMessage.add(touch); //add current 'touch' value to osc message 
    oscSend.send(tMessage, loc1); //send osc to Pi 1
    oscSend.send(tMessage, loc2); //send osc to Pi 2
    oscSend.send(tMessage, loc3); //send osc to Pi 3
    oscSend.send(tMessage, loc4); //send osc to Pi 4
    oscSend.send(tMessage, loc5); //send osc to Pi 5
    oscSend.send(tMessage, loc6); //send osc to Pi 6
    oscSend.send(tMessage, loc7); //send osc to Pi 7
    oscSend.send(tMessage, loc8); //send osc to Pi 8
    oscSend.send(tMessage, loc9); //send osc to Pi 9
    
  }
  
  if (tData.charAt(0) == 'R'){ //if current touch data is marked 'R', received from Arduino
  
  /* The release data is not send to the Pis because based on the way I am using the data to change the media files, ie a different
  pin (int) corresponds to a different part of the suit and different imagery, means that not sending the release data keeps the Pis
  on the previously touched sequence until a new one is triggered. If I had, for example, had a particular 'home' sequence that I had 
  wanted to display when the suit was not being touched, sending the data would have been useful.*/
    
    tData = tData.substring(1); //substring of data string for release
    release = int(tData); // value of 'release' variable equals touch data 'R' received, int
    
  }
  
  
}