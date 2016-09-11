#pragma once

#include "ofMain.h"
#include "ofxOsc.h" //system communication
#include "ofxOMXPlayer.h" //for playing videos on the Raspberry Pi

#define PORT 12435 //define osc receiver port, must be consistent with port number in Processing


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		

		ofxOscReceiver receiver; //to receive osc data from Processing

		int val; //int for storing touch value

        //if I were making a larger system, the media would be stored in directories. However, if I were making such a system, I likely wouldn't do it on a Raspberry Pi.
		ofxOMXPlayer player1, player2, player3; //variables for loading and displaying three videos

		ofImage im1, im2; //variables for loading and displaying two images

		ofSoundPlayer sound1; //variable for loading and playing sound 

};
