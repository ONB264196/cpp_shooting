#include"libOne.h"
#include"GAME.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include "GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {

}
void GAME_CLEAR::update()
{
	game()->playerBullets()->update();
	game()->enemyBullets()->update();

}
void GAME_CLEAR::draw() {
	clear();
	game()->draw();
	printSize(300);
	print("  GAME CLEAR");

}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScenes(GAME::TITLE_ID);
	}
}
#include "GAME_CLEAR.h"
