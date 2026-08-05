 #pragma once

struct Bullet {

    float startX;
    float startY;
    float x;
    float y;
    float damage;
    bool active;
    float fireRate;
    float speed;
    Bullet(float sX,float sY, float dx,float dy, float dmg, float fr, float spd);
    void update();
    
};