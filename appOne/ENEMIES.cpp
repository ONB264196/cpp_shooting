#include"CONTAINER.h"
#include"GAME.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER_BULLETS.h"
#include"HP_GAUGE.h"
#include "ENEMIES.h"

ENEMIES::ENEMIES(GAME* game) :
	GAME_OBJECT(game) {
}

ENEMIES::~ENEMIES()
{
	delete[] Enemies;
}

void ENEMIES::create()
{
	Enemy = game()->container()->enemy();
	Enemies = new ENEMY[Enemy.totalNum];
}

void ENEMIES::init()
{
	Enemy.centerPos = game()->container()->enemy().centerPos;

	float divTheta = 3.1415926f * 2 / Enemy.totalNum;
	float divInterval = Enemy.triggerInterval / Enemy.totalNum;
	for (int i = 0; i < Enemy.totalNum; i++) {
		Enemies[i].ofsTheta = divTheta * i;
		Enemies[i].triggerErapsTime = divInterval * i;
		Enemies[i].invincibleRestTime = 0;
		Enemies[i].hp = Enemy.initHp;
	}
	Enemy.curNum = Enemy.totalNum;
}

void ENEMIES::update()
{
	move();
	launch();
	collision();
}

void ENEMIES::move()
{
	if (Enemy.centerPos.y < Enemy.targetPosY) {
		Enemy.centerPos.y += Enemy.fallSpeed * delta;
	}
	for (int i = 0; i < Enemy.curNum; i++) {
		float theta = Enemy.refTheta + Enemies[i].ofsTheta;
		float px = Enemy.centerPos.x + cos(theta) * Enemy.majRadius;
		float py = Enemy.centerPos.y + sin(theta) * Enemy.minRadius;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}
	Enemy.refTheta += Enemy.thetaSpeed * delta;
}

void ENEMIES::launch()
{
	VECTOR2 playerPos = game()->player()->pos();
	for (int i = 0; i < Enemy.curNum; i++) {
		Enemies[i].triggerErapsTime += delta;
		if (Enemies[i].triggerErapsTime >= Enemy.triggerInterval) {
			VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
			VECTOR2 pos = Enemies[i].pos + launchVec * Enemy.ofsLaunchDist;
			game()->enemyBullets()->launch(pos, launchVec);
			Enemies[i].triggerErapsTime = 0;
		}
	}

}

void ENEMIES::collision()
	{
	BULLETS* bullets = game()->playerBullets();
	float distance = Enemy.bcRadius + bullets->bcRadius();
	float sqDistance = distance * distance;
	for (int j = Enemy.curNum - 1; j >= 0; j--) {
		if (Enemies[j].invincibleRestTime > 0) {
			Enemies[j].invincibleRestTime -= delta;
		}
		else {
			Enemies[j].color = Enemy.normalColor;
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
				if (sqLength(vec) < sqDistance) {
					Enemies[j].hp--;
					Enemies[j].invincibleRestTime = Enemy.invincibleTime;
					Enemies[j].color = Enemy.collisionColor;
					if (Enemies[j].hp <= 0) {
						Enemy.curNum--;
						Enemies[j] = Enemies[Enemy.curNum];
					}
					bullets->kill(i);
					i = 0;
				}
			}
		}
	}
}

void ENEMIES::draw()
{
	for (int i = 0; i < Enemy.curNum; i++) {
		imageColor(Enemies[i].color);
		image(Enemy.img, Enemies[i].pos.x, Enemies[i].pos.y);
		game()->hpGauge()->draw(Enemies[i].pos, Enemy.hpGaugeofs, Enemies[i].hp);
	}
}
