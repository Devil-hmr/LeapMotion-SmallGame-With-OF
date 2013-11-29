#pragma once
#include "ofGraphics.h"

#define GAME_WIDTH 600
#define GAME_HEIGHT 400

#define OFFSETX 50
#define OFFSETY 100

#define SIZE_F_S 20


class FoodMorsel: public ofRectangle
{
public:

  FoodMorsel();
	int getRedColorValue();
	int getGreenColorValue();
	int getBlueColorValue();
	void refreshFood();
private:
	int color[3];

};

