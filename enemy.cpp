#include<iostream>
#include<cstdlib>
#include"enemy.h"
#include<unordered_map>
#include<vector>
#include<cmath>

Enemy::Enemy(std::string n, float spawnX ,float spawnY,int hth,float spd, float rate, float dmg){

    name = n;
    health = hth    ;
    alive = true;
    x = spawnX;
    y = spawnY;
    speed = spd;
}

void Enemy::update() {

}

Enemy Enemy::spawn(){

    static std::vector<std::string> enemyNames = { // staatic so dictionary doesn't always get buil in ram from 0
        "Doom Scrolling","Procrastination","Random Distraction","No sleeper", "Junk Food"
    };

    struct EnemyInfo {
        int health;
        float speed;
    };

    static std::unordered_map<std::string,EnemyInfo> enemyPowers = {

        {"Doom Scrolling",{50,0.5f,1.5f,30}},
        {"Procrastination",{200,0.2f,4,50}},
        {"Random Distraction",{20,1.5f,1.0f,20}},
        {"No Sleeper",{250,0.1f,5.0f,70}},
        {"Junk Food",{100,1.0f,3.0f,50}}
    };

    // setting up the spawn point
    int spawnX = (rand() % 20) - 10;
    int spawnY = (rand() % 20) - 10;

    //algorith for randomizing type of enemy
    std::string randName;
    int randHealth;

    int choice = rand() % enemyNames.size();
    
    randName = enemyNames[choice];
    EnemyInfo info = enemyPowers[randName]; 
    return Enemy(randName,spawnX,spawnY,info.health,info.speed);

    
}