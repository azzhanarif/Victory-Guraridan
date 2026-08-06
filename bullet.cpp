#include<iostream>
#include"bullet.h"
#include<cmath>

Bullet::Bullet(float sX,float sY, float dx,float dy,float dmg, float fr, float spd){

    startX = sX;
    startY = sY;
    x = dx;
    y = dy;
    damage = dmg;
    fireRate = fr;
    speed = spd;
    active = true;

}

void Bullet::update(){

        startX += x * speed;
        startY += y * speed;

}
