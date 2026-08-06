#pragma once
#include"gun.h"

struct Player {

    float x;
    float y;
    float focusPoints;
    int level;
    Player(gun mygun);
    void move();
    gun getGun;
    void gunLevel();

};