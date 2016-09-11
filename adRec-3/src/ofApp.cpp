#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

receiver.setup(PORT); //set up osc receiver

string vPath1 = ofToDataPath("../../../adRec/bin/data/AA.mov",true); //set data path for sequence 1
string vPath2 = ofToDataPath("../../../adRec/bin/data/ab.mov",true); //set data path for sequence 2


sound1.load("breathe6.wav"); //load sound file

sound1.setLoop(true); //loop sound file
sound1.setSpeed(1.0); //set normal speed for sound (range 0-2.0)
sound1.setVolume(0.6f); //set volume (0-1)

player1.loadMovie(vPath1); //load sequence one via data path
player2.loadMovie(vPath2); //load sequence two via data path

im1.loadImage("3.jpg"); //load sequence three
im2.loadImage("4.jpg"); //load sequence four
im3.loadImage("5.jpg"); //load sequence five

im1.resize(ofGetWidth(), ofGetHeight()); //resize image three to window
im2.resize(ofGetWidth(), ofGetHeight()); //resize image four to window
im3.resize(ofGetWidth(), ofGetHeight()); //resize image five to window

sound1.play(); //play the sound file


}

//--------------------------------------------------------------
void ofApp::update(){

while(receiver.hasWaitingMessages()){ //while there are osc messages coming in
ofxOscMessage v; //osc message variable
receiver.getNextMessage(&v); //receive next message at osc variable address

if(v.getAddress()=="/touch"){ //if the osc message received is prefixed 'touch'
//don't receive messages without the correct prefix

val=v.getArgAsInt32(0); //data should be int

}

sound1.setSpeed(val/5.0); //slow down sound while data is coming in

}



}

//--------------------------------------------------------------
void ofApp::draw(){

im2.draw(0,0,ofGetWidth(), ofGetHeight()); //play on start



if (val == 2){ // if val is '2'

im2.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 4


}

if (val == 3){ //if val is '3'

im3.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 5


}

if (val == 5){ // if val is '5'

player1.draw(0,0,ofGetWidth(), ofGetHeight()); //sequence 1

}

if (val == 7){ //if val is '7'

player2.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 2

}

if (val == 8){ //if val is '8'

im1.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 3

}

if (val == 1){ //if val is '6'
    
sound1.setVolume(1.0); //play sound full volume
    //each sound is contained in the individual code for the Pi it runs on and has a separate trigger area
    //while all of them have the image and video sequence, though each is different
}




}

