#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include "STAGE.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE()
{
}
void STAGE::init()
{
	game()->playerBullets()->init();
	game()->enemyBullets()->init();
	game()->player()->init();
	game()->enemies()->init();
}
void STAGE::update()
{
	game()->playerBullets()->update();
	game()->enemyBullets()->update();
	game()->player()->update();
	game()->enemies()->update();
}
void STAGE::draw() {
	clear();
	game()->draw();
}
void STAGE::nextScene() {
	if (game()->enemies()->curNum() <= 0) {
		game()->changeScenes(GAME::GAME_CLEAR_ID);
	}
	else if (game()->player()->hp() <= 0) {
		game()->changeScenes(GAME::GAME_OVER_ID);
	}
}