#include "CONTAINER.h"
void CONTAINER::load(){
	setData();
	loadGraphic();
}
void CONTAINER::setData(){
	Data.title.backColor = COLOR(0, 20, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.textSize = 400;
	Data.title.pos.x = 180;
	Data.title.pos.y = 700;
	strcpy_s(Data.title.str, "KUNOICHI");

	Data.player.angle = 0;
	Data.player.advSpeed = 0;
	Data.player.defSpeed = 600;
	Data.player.sftSpeed = 200;
	Data.player.pos.x = 960;
	Data.player.pos.y = 970;
	Data.player.limmitW = 100;
	Data.player.launchVec = VECTOR2(0, -1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.03125f;
	Data.player.ofsLaunchDist = 100;
	Data.player.bcRadius = 20;
	Data.player.invincibleRestTime = 0;
	Data.player.invincibleTime = 0.05f;
	Data.player.hp = 5;
	Data.player.hpGaugeofs = VECTOR2(0, -120);
	Data.player.collisionColor = COLOR(255, 0, 0);
	Data.player.normalColor = COLOR(255, 255, 255);

	Data.enemy.totalNum = 8;
	Data.enemy.curNum = Data.enemy.totalNum;
	Data.enemy.majRadius = 700;
	Data.enemy.minRadius = 100;
	Data.enemy.centerPos = VECTOR2(960, -300);
	Data.enemy.fallSpeed = 60;
	Data.enemy.targetPosY = 300;
	Data.enemy.refTheta = 0;
	Data.enemy.thetaSpeed = 0.6f;
	Data.enemy.triggerInterval = 0.65f;
	Data.enemy.ofsLaunchDist = 100;
	Data.enemy.bcRadius = 20;
	Data.enemy.invincibleTime = 0.05f;
	Data.enemy.initHp = 5;
	Data.enemy.hpGaugeofs = VECTOR2(0, -120);
	Data.enemy.collisionColor = COLOR(255, 0, 0);
	Data.enemy.normalColor = COLOR(255, 255, 255);


	Data.playerBullet.totalNum = 30;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 6000;
	Data.playerBullet.angSpeed = 10;
	Data.playerBullet.bcRadius = 20;
	

	Data.enemyBullet.totalNum = 20;
	Data.enemyBullet.curNum = 0;
	Data.enemyBullet.advSpeed = 1000;
	Data.enemyBullet.angSpeed = 0;
	Data.enemyBullet.bcRadius = 5;

	Data.hpGauge.coWidth = 30;
	Data.hpGauge.high = 15;
	Data.hpGauge.safeColor = COLOR(0, 255, 0);
	Data.hpGauge.dangerColor = COLOR(255, 0, 0);
}
void CONTAINER::loadGraphic() {
	Data.player.img = loadImage("assets\\player.png");
	Data.enemy.img = loadImage("assets\\enemy.png");
	Data.playerBullet.img = loadImage("assets\\pBullet.png");
	Data.enemyBullet.img = loadImage("assets\\eBullet.png");
}
