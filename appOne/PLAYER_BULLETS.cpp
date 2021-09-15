#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER_BULLETS.h"


PLAYER_BULLETS::PLAYER_BULLETS(GAME* game):
	BULLETS(game){
}

void PLAYER_BULLETS::create()
{
	setBullets(game()->container()->playerBullet());
}
