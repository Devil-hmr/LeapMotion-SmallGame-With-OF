#include "gameApp.h"

//--------------------------------------------------------------
void gameApp::setup(){
	ofSetFrameRate(60);
	// Have the sample listener receive events from the controller
	controller.addListener(listener); 
	snake = new SnakeGame();
}

//--------------------------------------------------------------
void gameApp::update(){
	snake->update();
}

//--------------------------------------------------------------
void gameApp::draw(){
	snake->draw();
}

//--------------------------------------------------------------
void gameApp::exit(){
	// Remove the sample listener when done
	controller.removeListener(listener);
}
//--------------------------------------------------------------
void gameApp::keyPressed(int key){
	snake->keyPressed(key);
}

//--------------------------------------------------------------
void gameApp::keyReleased(int key){
	snake->keyReleased(key);
}

//--------------------------------------------------------------
void gameApp::mouseMoved(int x, int y ){
	snake->mouseMoved(x,y);
}

//--------------------------------------------------------------
void gameApp::mouseDragged(int x, int y, int button){
	snake->mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void gameApp::mousePressed(int x, int y, int button){
	snake->mousePressed(x,y,button);
}

//--------------------------------------------------------------
void gameApp::mouseReleased(int x, int y, int button){
	snake->mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void gameApp::windowResized(int w, int h){
	snake->windowResized(w,h);
}

//--------------------------------------------------------------
void gameApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void gameApp::dragEvent(ofDragInfo dragInfo){ 
}