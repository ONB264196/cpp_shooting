#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include "PLAYER.h"
PLAYER::PLAYER(GAME* game):
    GAME_OBJECT(game){
}
void PLAYER::create(){
    Player = game()->container()->player();
}
void PLAYER::init(){
    Player.pos = game()->container()->player().pos;
    Player.hp = game()->container()->player().hp;
}
void PLAYER::update() {
    move();
    launch();
    collision();
}
void PLAYER::move() {
    if (isPress(KEY_SHIFT)) {
        Player.advSpeed = Player.sftSpeed;
    }
    else {
        Player.advSpeed = Player.defSpeed;
    }
    if (Player.pos.x > Player.limmitW) {
        if (isPress(KEY_A) || isPress(KEY_LEFT)) {
            Player.pos.x += -Player.advSpeed * delta;
        }
    }
    if (Player.pos.x < width - Player.limmitW) {
        if (isPress(KEY_D) || isPress(KEY_RIGHT)) {
            Player.pos.x += Player.advSpeed * delta;
        }
    }
}
void PLAYER::launch() {
    if (isPress(KEY_SPACE)) {
        Player.triggerErapsedTime = Player.triggerInterval;
    }
    else {
        Player.triggerErapsedTime += delta;
        if (Player.triggerErapsedTime >= Player.triggerInterval) {
            VECTOR2 pos = Player.pos + Player.launchVec * Player.ofsLaunchDist;
            game()->playerBullets()->launch(pos, Player.launchVec);
            Player.triggerErapsedTime = 0;
        }
    }
}
void PLAYER::collision()
{
    if (Player.invincibleRestTime > 0) {
        Player.invincibleRestTime -= delta;
    }
    else {
        Player.color = Player.normalColor;
        ENEMY_BULLETS* bullets = game()->enemyBullets();
        float distance = Player.bcRadius + bullets->bcRadius();
        float sqDistance = distance * distance;
        for (int i = bullets->curNum() - 1; i >= 0; i--) {
            VECTOR2 vec = Player.pos - bullets->pos(i);
            if (sqLength(vec) < sqDistance) {
                Player.hp--;
                Player.invincibleRestTime = Player.invincibleTime;
                Player.color = Player.collisionColor;
                bullets->kill(i);
                i = 0;
            }
        }
    }
}
void PLAYER::draw() {

    imageColor(Player.color);
    rectMode(CENTER);
    image(Player.img, Player.pos.x, Player.pos.y, Player.angle);

    game()->hpGauge()->draw(Player.pos, Player.hpGaugeofs, Player.hp);
}
