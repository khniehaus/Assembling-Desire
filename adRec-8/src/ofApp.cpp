#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

receiver.setup(PORT); //set up osc receiver

string vPath1 = ofToDataPath("../../../adRec/bin/data/2.mov",true); // set data path for sequence 2
string vPath2 = ofToDataPath("../../../adRec/bin/data/3.mov",true); //set data path for sequence 3
string vPath3 = ofToDataPath("../../../adRec/bin/data/4.mov",true); //set data path for sequence 4


sound1.load("breathe7.wav"); //load sound

sound1.setLoop(true); //loop the sound file
sound1.setSpeed(1.0); //set normal speed for sound (0-2.0)
sound1.setVolume(0.6f); //set volume (0-1.0)

player1.loadMovie(vPath1); //load sequence 2 via data path
player2.loadMovie(vPath2); //load sequence 3 via data path
player3.loadMovie(vPath3); //load sequence 4 via data path

im1.loadImage("1.jpg"); //load sequence 1 image
im2.loadImage("5.jpg"); //load sequence 5 image


im1.resize(ofGetWidth(), ofGetHeight()); //resize image 1 to screen
im2.resize(ofGetWidth(), ofGetHeight()); //resize image 5 to screen

sound1.play(); //play sound

}

//--------------------------------------------------------------
void ofApp::update(){

while(receiver.hasWaitingMessages()){ //while there are osc messages coming in
ofxOscMessage v; //osc message variable
receiver.getNextMessage(&v); //receive next message at osc variable address

if(v.getAddress()=="/touch"){ //if the osc message is prefixed 'touch'
//don't receive messages without the correct prefix

val=v.getArgAsInt32(0); //data should be int

}

if (val >= 4){ //if incoming data is '3' or above (10 possible)

sound1.setSpeed(val/5.0); //increase speed according to data value (0-2.0)

}
}

}

//--------------------------------------------------------------
void ofApp::draw(){

player3.draw(0,0,ofGetWidth(), ofGetHeight()); //play on start


if (val == 2){ // if val is 2

player3.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 4


}

if (val == 3){ //if val is 3

im2.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 5


}


if (val == 5){ //if val is 5

im1.draw(0,0,ofGetWidth(), ofGetHeight()); //sequence 1

}

if (val == 7){ //if val is 7

player1.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 2

}

if (val == 8){ //if val is 8

player2.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 3

}

if (val == 4){ //if val is 6

sound1.setVolume(1.0); //play sound full volume
    
    //each sound is contained in the individual code for the Pi it runs on and has a separate trigger area
    //while all of them have the image and video sequence, though each is different

}



}

