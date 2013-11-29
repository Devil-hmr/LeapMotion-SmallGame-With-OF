#ifndef __LEAP_LISTENER_H__
#define  __LEAP_LISTENER_H__

#include "ofMain.h"
#include "Leap.h"
using namespace Leap;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class LeapListener : public Listener{

public:
	virtual void onInit(const Controller&);
	virtual void onConnect(const Controller&);
	virtual void onDisconnect(const Controller&);
	virtual void onExit(const Controller&);
	virtual void onFrame(const Controller&);
	virtual void onFocusGained(const Controller&);
	virtual void onFocusLost(const Controller&);
	//////////////////////////////////////////////////////////////////////////
	static ofEvent<ofVec3f> GestureEvent;
	static ofEvent<ofPoint> FingerMoveEvent;
	static ofEvent<ofPoint> FingerTouchEvent;

public:
	ofPoint getScreenPosition(Frame frame,Finger finger);
};

#endif