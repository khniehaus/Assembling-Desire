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

		ofxOMXPlayer player1, player2, player3; //variables for loading and displaying three videos

		ofImage im1, im2; //variables for loading and displaying two images


};
