#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {

}
void GAME_OVER::update()
{
	game()->playerBullets()->update();
	game()->enemyBullets()->update();
	game()->enemies()->move();
}
void GAME_OVER::draw() {
	clear();
	game()->draw();
	printSize(300);
	print("GAME OVER");
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScenes(GAME::TITLE_ID);
	}

}
