#include"CONTAINER.h"
#include"GAME.h"
#include "HP_GAUGE.h"

HP_GAUGE::HP_GAUGE(GAME* game) : 
	GAME_OBJECT(game){
}

void HP_GAUGE::create()
{
	HpGauge = game()->container()->hpGauge();
}

void HP_GAUGE::draw(VECTOR2 pos, VECTOR2 ofs, int hp)
{
	if (hp > 1) {
		fill(HpGauge.safeColor);
	}
	else {
		fill(HpGauge.dangerColor);
	}
	pos += ofs;
	rect(pos.x, pos.y, hp * HpGauge.coWidth, HpGauge.high);
}
