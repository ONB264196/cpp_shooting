#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class HP_GAUGE :
    public GAME_OBJECT
{
public:
    struct DATA {
        COLOR safeColor;
        COLOR dangerColor;
        float coWidth;
        float high;
    };
private:
    DATA HpGauge;
public:
    HP_GAUGE(class GAME* game);
    void create();
    void draw(VECTOR2 pos, VECTOR2 ofs, int hp);
};

