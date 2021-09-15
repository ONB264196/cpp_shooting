#pragma once
#include"TITLE.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BULLETS.h"
#include"HP_GAUGE.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		PLAYER::DATA player;
		ENEMIES::DATA enemy;
		BULLETS::DATA playerBullet;
		BULLETS::DATA enemyBullet;
		HP_GAUGE::DATA hpGauge;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const TITLE::DATA& title() { return Data.title; }
	const PLAYER::DATA& player() { return Data.player; }
	const ENEMIES::DATA& enemy() { return Data.enemy; }
	const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
	const BULLETS::DATA& enemyBullet() { return Data.enemyBullet; }
	const HP_GAUGE::DATA& hpGauge() { return Data.hpGauge; }
};
