#pragma once

struct Enemy{

    std::string name;
    int health;
    float x;
    float y;
    bool alive;
    float speed;
    float hitRate;
    float Damage;
    float attackRate;
    float attackDamage;
    float attackTimer;


    Enemy(std::string n,float spawnX,float spawnY,int hth,float spd,float rate, float dmg);
    void update();
    static Enemy spawn();
    void damage();
    void attackBase();

};