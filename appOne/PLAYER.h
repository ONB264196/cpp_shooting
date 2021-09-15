#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        float advSpeed;
        float defSpeed;
        float sftSpeed;
        float angle;
        float limmitW;
        //launch
        VECTOR2 launchVec;
        float triggerErapsedTime;
        float triggerInterval;
        float ofsLaunchDist;
        //collision
        float bcRadius;
        float invincibleTime;
        float invincibleRestTime;
        int hp;
        VECTOR2 hpGaugeofs;
        COLOR collisionColor;
        COLOR normalColor;
        COLOR color;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
        void move();
        void launch();
        void collision();
    void draw();
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
};