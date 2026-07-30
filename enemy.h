#pragma once

struct Enemy{

    int health;
    int x;
    int y;
    bool alive;

    Enemy(int spawnX,int spawnY,int hth);
    void update();

};