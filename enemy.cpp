#include<iostream>
#include"enemy.h"

Enemy::Enemy(int spawnX ,int spawnY,int hth){

    health = hth;
    alive = true;
    x = spawnX;
    y = spawnY;
}

void Enemy::update(){ // creeping towards centre

    if(x != 0 || y != 0){
        if (x < 0) x+=1.0f;
        if (x > 0) x-=1.0f;
        if (y > 0) y-=1.0f;
        if (y < 0) y+=1.0f;
    }
}