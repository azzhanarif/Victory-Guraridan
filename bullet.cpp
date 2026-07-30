#include<iostream>
#include"bullet.h"

Bullet::Bullet(float sX,float sY, float dx,float dy){

    startX = sX;
    startY = sY;
    x = dx;
    y = dy;

    active = true;

}
