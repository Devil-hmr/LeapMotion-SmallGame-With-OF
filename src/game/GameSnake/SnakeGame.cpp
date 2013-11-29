#include "SnakeGame.h"
#include "../../leap/LeapListener.h"

SnakeGame::SnakeGame(){

	snake = new Snake(1,OFFSETX+SIZE_F_S*10,OFFSETY + SIZE_F_S*10);
	food = new FoodMorsel();

	gameScore = 0;
	game_state = "PLAYING";	// The initial state is set as playing when the program begings

	// Loading the fonts that will be used in the game
	scoreFont.loadFont("font.TTF", 16);
	pausedFont.loadFont("font.TTF", 16);	


	ofAddListener(LeapListener::GestureEvent , this, &SnakeGame::gestureEventCallBack);
	//ofAddListener(LeapListener::FingerMoveEvent , this, &SnakeGame::fingerMoveEventCallBack);
	//ofAddListener(LeapListener::FingerTouchEvent , this, &SnakeGame::fingerTouchEventCallBack);
}
void SnakeGame::gestureEventCallBack(ofVec3f &gesture){

	////
	if(int(gesture.z)!= Gesture::TYPE_SWIPE){
		return;
	}
	if(fabs(gesture.x)>fabs(gesture.y)){
		//x
		if(gesture.x>0){
			//+x
			if(snake->getYDirection()){
				snake->setXDirection(1);
				snake->setYDirection(0);
			}
		}
		else{
			//-x
			if(snake->getYDirection()){
				snake->setXDirection(-1);
				snake->setYDirection(0);
			}
		}

	}
	else{
		//y
		if(gesture.y>0){
			//-y
			if(snake->getXDirection()){
				snake->setYDirection(-1);
				snake->setXDirection(0);
			}
		}
		else{
			//+y
			if(snake->getXDirection()){
				snake->setYDirection(1);
				snake->setXDirection(0);
			}
		}
	}



}

SnakeGame::~SnakeGame(){
}
//--------------------------------------------------------------
void SnakeGame::update(){
	if(ofGetFrameNum()%30!=0){
		return;
	}

	if (game_state == "PLAYING"){
		snake->move();
		if(snakeOverFood()){
			snake->eat(food);
			gameScore += 5*snake->getBodyLength();
			food->refreshFood();
		}
		if(snakeIsColliding())
			game_state = "OVER";
	}
}

//--------------------------------------------------------------
void SnakeGame::draw(){
	ofPushStyle();
	ofSetColor(0,0,0);
	ofNoFill();
	ofRect(OFFSETX,OFFSETY,GAME_WIDTH,GAME_HEIGHT);

	//for (int i = 0;i<GAME_WIDTH/SIZE_F_S;i++)
	//{
	//	ofLine(i*SIZE_F_S+ OFFSETX,OFFSETY,i*SIZE_F_S+ OFFSETX,GAME_HEIGHT + OFFSETY);
	//}
	//for (int j = 0;j<GAME_HEIGHT/SIZE_F_S;j++)
	//{
	//	ofLine(OFFSETX,j*SIZE_F_S+ OFFSETY,GAME_WIDTH + OFFSETX,j*SIZE_F_S+ OFFSETY);
	//}
	scoreFont.drawString("LeapMotion(体感) 小游戏——贪食蛇",OFFSETX,OFFSETX);
	
	ofPopStyle();

	// The snake will always be drawn in the background, even if some sort of paused or game over screen
	// is covering part of it up
	drawSnake();
	drawFood();
	drawScore();

	if(game_state == "OVER"){
		// Code to draw a game over screen
		scoreFont.drawString("雅蠛蝶，挂了",GAME_WIDTH/2,GAME_HEIGHT/2);
	}

	if(game_state == "PAUSED"){
		drawPauseScreen();
	}
}

//--------------------------------------------------------------
void SnakeGame::keyPressed(int key){
	// Move up if currently moving in a horizontal direction
	if(key == OF_KEY_UP ){
		if(snake->getXDirection()){
			snake->setYDirection(-1);
			snake->setXDirection(0);
		}
	}
	// Move down if currently moving in a horizontal direction
	if(key == OF_KEY_DOWN){
		if(snake->getXDirection()){
			snake->setYDirection(1);
			snake->setXDirection(0);
		}
	}
	// Move right if currently moving in a vertical direction
	if(key == OF_KEY_RIGHT){
		if(snake->getYDirection()){
			snake->setXDirection(1);
			snake->setYDirection(0);
		}
	}
	// Move left if currently moving in a vertical direction
	if(key == OF_KEY_LEFT){
		if(snake->getYDirection()){
			snake->setXDirection(-1);
			snake->setYDirection(0);
		}
	}

	if(key == 'p'){
		// If the game is not paused and the game is not over, pause the game, otherwise start the game up again
		if(game_state != "OVER" && game_state != "WELCOME"){
			if(game_state == "PAUSED"){
				game_state = "PLAYING";
			}
			else{
				game_state = "PAUSED";	// Test button to see what happens when the "OVER" state is entered
			}
		}

	}
}

//--------------------------------------------------------------
void SnakeGame::keyReleased(int key){

}

//--------------------------------------------------------------
void SnakeGame::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void SnakeGame::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::windowResized(int w, int h){

}

bool SnakeGame::snakeOverFood(){
	BodySegment snakeHead = snake->getSegmentAt(0);
	return snakeHead.intersects(ofRectangle(food->x,food->y,food->width,food->height));	// Checking to see if the snake head is on top of the food
}
// Checks to see if the head of the snake is colliding with the boundry of the screen or with itself
// returns true if the snake is colliding with something it shouldn't be
bool SnakeGame::snakeIsColliding(){
	bool isSnakeColliding = false;
	// Storing the head of the snake in variable
	BodySegment snakeHead = snake->getSegmentAt(0);
	isSnakeColliding = snake->isOutOfBounds(OFFSETX,OFFSETY,GAME_WIDTH+OFFSETX,GAME_HEIGHT+OFFSETY);	// If the snake is out of bounds, then the function returns true
	for(int i=2; i < snake->getBodyLength() - 2; i++){
		if(snakeHead.intersects(snake->getSegmentAt(i))){
			isSnakeColliding = true;
		}
	}
	return isSnakeColliding;	// Default set to false, the code will return true if there is a collision
}

void SnakeGame::drawSnake(){
	for(int i= 0; i < snake->getBodyLength(); i++){
		ofSetColor(snake->getSegmentAt(i).getRedValue(), 
			snake->getSegmentAt(i).getGreenValue(), 
			snake->getSegmentAt(i).getBlueValue());
		ofRect(snake->getSegmentAt(i).x, 
			snake->getSegmentAt(i).y, 
			snake->getSegmentAt(i).WIDTH, 
			snake->getSegmentAt(i).HEIGHT);
	}
}
void SnakeGame::drawFood(){
	ofSetColor(food->getRedColorValue(), food->getGreenColorValue(), food->getBlueColorValue());
	ofRect(food->x, food->y, food->width, food->height);
}

// Draws the current score to the screen
void SnakeGame::drawScore(){
	// Converting the integer game score to a string
	string stringScore;
	ostringstream convert;
	convert << gameScore;
	stringScore = convert.str();

	// Drawing the string to the screen using the ofDrawBitmap string function
	ofSetColor(0, 0, 0);	// Setting the color to a nice tan hue
	float x = GAME_WIDTH + OFFSETX + OFFSETX;
	float y =  3*OFFSETX;
	scoreFont.drawString(stringScore, x, y);

	scoreFont.drawString("分数",x,y - OFFSETX);

}

// Draws a pause screen
void SnakeGame::drawPauseScreen(){
	ofSetColor(139, 26, 26);	// Setting the pause text to a firebrick color
	float pauseStringXCoord = (GAME_WIDTH/2) - 100;
	float pauseStringYCoord = GAME_HEIGHT/2;
	pausedFont.drawString("Game Paused", pauseStringXCoord, pauseStringYCoord);
	pausedFont.setLineHeight(10);
	pausedFont.drawString("Press p to unpause", GAME_WIDTH/4, pauseStringYCoord + 90);
}


