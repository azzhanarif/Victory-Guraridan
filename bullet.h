#pragma once

struct Bullet {

    float startX;
    float startY;
    float x;
    float y;
    bool active;

    Bullet(float sX,float sY, float dx,float dy);
    void update();
    
};