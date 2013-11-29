#pragma once

#include "ofMain.h"
#include "leap/LeapListener.h"
#include "game/GameSnake/SnakeGame.h"

class gameApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		//////////////////////////////////////////////////////////////////////////
		// Create a sample listener and controller
		LeapListener listener;

		Controller controller;

		//game
private:
	SnakeGame *snake;
};
