#include "Game.h"


Game::Game(void){
	ofAddListener(ofEvents().setup, this, &Game::_setup);
	ofAddListener(ofEvents().update, this, &Game::_update);
	ofAddListener(ofEvents().draw, this, &Game::_draw);
}
Game::~Game(void){

}

void Game::_setup(ofEventArgs &e){
	setup();
}
void Game::_update(ofEventArgs &e){
	update();
}
void Game::_draw(ofEventArgs &e){
	draw();
}