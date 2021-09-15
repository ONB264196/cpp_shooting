#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMY_BULLETS.h"

ENEMY_BULLETS::ENEMY_BULLETS(class GAME* game) :
	BULLETS(game) {
}

void ENEMY_BULLETS::create()
{
	setBullets(game()->container()->enemyBullet());
}
