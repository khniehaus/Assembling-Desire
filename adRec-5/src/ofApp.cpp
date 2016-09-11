#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

receiver.setup(PORT); //set up osc receiver

string vPath1 = ofToDataPath("../../../adRec/bin/data/2.mov",true); //set data path for sequence 2
string vPath2 = ofToDataPath("../../../adRec/bin/data/5.mov",true); //set data path for sequence 5

player1.loadMovie(vPath1); //load sequence 2 via data path
player2.loadMovie(vPath2); //load sequence 5 via data path

im1.loadImage("1.jpg");//load sequence 1
im2.loadImage("3.jpg"); //load sequence 3
im3.loadImage("4.jpg"); //load sequence 4

im1.resize(ofGetWidth(), ofGetHeight()); //resize image 1 to screen
im2.resize(ofGetWidth(), ofGetHeight()); //resize image 3 to screen
im3.resize(ofGetWidth(), ofGetHeight()); //resize image 4 to screen

}

//--------------------------------------------------------------
void ofApp::update(){

while(receiver.hasWaitingMessages()){ //while there are osc messages coming in
ofxOscMessage v; //osc message variable
receiver.getNextMessage(&v); //receive next message at osc variable address

if(v.getAddress()=="/touch"){ // if the osc message received is prefixed 'touch'
//don't receive messages without the correct prefix

val=v.getArgAsInt32(0); //data should be int

}

}

}

//--------------------------------------------------------------
void ofApp::draw(){

im2.draw(0,0,ofGetWidth(), ofGetHeight()); //play on start



if (val == 2){ // if 'val' is '2'

im3.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 4


}

if (val == 3){ //if 'val' is '3'

player2.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 5


}

if (val == 5){ //if 'val' is '5'

im1.draw(0,0,ofGetWidth(), ofGetHeight()); //sequence 1

}

if (val == 7){ //if 'val' is '7'

player1.draw(0,0,ofGetWidth(), ofGetHeight()); //sequence 2

}

if (val == 8){ //if 'val' is '8'

im2.draw(0,0, ofGetWidth(), ofGetHeight()); //sequence 3

}



}

