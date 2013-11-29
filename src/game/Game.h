#pragma once
#include "ofMain.h"

class Game{
public:
	Game(void);
	~Game(void);
protected:
	void _setup(ofEventArgs &e);
	void _update(ofEventArgs &e);
	void _draw(ofEventArgs &e);
public:
	virtual void setup()	{}			// called when app starts
	virtual void update()	{}			// called every frame to update object
	virtual void draw()		{}			// called every frame to draw object
};
