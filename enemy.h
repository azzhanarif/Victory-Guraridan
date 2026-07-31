#pragma once

struct Enemy{

    std::string name;
    int health;
    float x;
    float y;
    bool alive;
    float speed;

    Enemy(std::string n,float spawnX,float spawnY,int hth,float spd);
    void update();
    static Enemy spawn();

};