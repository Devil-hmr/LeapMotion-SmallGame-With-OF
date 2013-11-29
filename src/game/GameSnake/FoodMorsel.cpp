#include "FoodMorsel.h"
#include <time.h>
#include "stdlib.h"


FoodMorsel::FoodMorsel()
{
  // Initializing the width and height, which are the width and height
	width = SIZE_F_S;
	height = SIZE_F_S;

	//

	x = int(ofRandom(0,GAME_WIDTH/SIZE_F_S - 1))*SIZE_F_S + OFFSETX;
	y = int(ofRandom(0,GAME_HEIGHT/SIZE_F_S - 1))*SIZE_F_S  + OFFSETY;

	// Initializing the random seed for the relocated function
	ofSeedRandom();

	// Initalizing the first color
	color[0] = 0;
	color[1] = 255;
	color[2] = 0;
	
}

int FoodMorsel::getRedColorValue(){
	return color[0];
}

int FoodMorsel::getGreenColorValue(){
	return color[1];
}

int FoodMorsel::getBlueColorValue(){
	return color[2];
}

// Everytime the snake eats a food morsel on the screen, the food morsel has to relocate
// The reolocate function changes the location of the food, and gives it a new color
void FoodMorsel::refreshFood(){
	// Creating a new random color
	for(int i=0; i < 3; i++){
		color[i] = rand() % 255;
	}

	x = int(ofRandom(0,GAME_WIDTH/SIZE_F_S - 1))*SIZE_F_S + OFFSETX;
	y = int(ofRandom(0,GAME_HEIGHT/SIZE_F_S - 1))*SIZE_F_S  + OFFSETY;
}

