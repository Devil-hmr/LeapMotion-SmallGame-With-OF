#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "Snake.h"
#include "FoodMorsel.h"
#include "ofxTrueTypeFontUC.h"

class SnakeGame{

public:
	SnakeGame();
	~SnakeGame();
public:
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
public:
	FoodMorsel *food;
	Snake *snake;
	int gameScore;
	string game_state;
	ofxTrueTypeFontUC scoreFont;
	ofxTrueTypeFontUC pausedFont;


	void gestureEventCallBack(ofVec3f &gesture);

public:
	void drawSnake();
	bool snakeOverFood();
	void drawFood();
	bool snakeIsColliding();
	void drawPauseScreen();
	void drawScore();
};

#endif
