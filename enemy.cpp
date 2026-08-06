#include<iostream>
#include<cstdlib>
#include"enemy.h"
#include<unordered_map>
#include<vector>
#include<cmath>

Enemy::Enemy(std::string n, float spawnX ,float spawnY,int hth,float spd, float rate, float dmg){
    name = n;
    health = hth;
    alive = true;
    x = spawnX;
    y = spawnY;
    speed = spd;
    
    attackRate = rate;
    attackDamage = dmg;
    
    attackTimer = 0.0f; 
}

void Enemy::attackBase(){
// to be filled by mufleh ahmed choda pro
}
void Enemy::update() {

    float disX = 0.0f - x; 
    float disY = 0.0f - y;
    float dis = std::sqrt((disX * disX) + (disY * disY));

    if (dis > speed) {
        // We use += because disX and disY already contain the correct +/- signs
        x += (disX / dis) * speed;
        y += (disY / dis) * speed;
    } 
    else {
        x = 0;
        y = 0;

        attackTimer += 0.0166f; 

        if (attackTimer >= attackRate) {
            attackBase(); 
            attackTimer = 0.0f; 
        }
    }
}

Enemy Enemy::spawn(){

    static std::vector<std::string> enemyNames = { 
        "Doom Scrolling","Procrastination","Random Distraction","No sleeper", "Junk Food"
    };

    struct EnemyInfo {
        int health;
        float speed;
        float rate;
        float damage;
    };

    static std::unordered_map<std::string,EnemyInfo> enemyPowers = {
        {"Doom Scrolling",{50, 0.08333f, 1.5f, 30}},
        {"Procrastination",{200,0.05, 4.0f, 50}},
        {"Random Distraction",{20, 0.125f, 1.0f, 20}},
        {"No sleeper",{250, 0.025, 5.0f, 70}},
        {"Junk Food",{100, 0.0625f, 3.0f, 50}}
    };

    float spawnX = 0.0f;
    float spawnY = 0.0f;

    // Flip a coin (0 or 1) to decide if we spawn on the Top/Bottom OR Left/Right
    if (rand() % 2 == 0) {
        // Horizontal Edge (Top or Bottom)
        spawnX = (rand() % 40) - 20.0f;                 // Random X anywhere from -20 to 20
        spawnY = (rand() % 2 == 0) ? -22.0f : 22.0f;    // Exactly at the top edge (-22) OR bottom edge (+22)
    }
    else {
        // Vertical Edge (Left or Right)
        spawnX = (rand() % 2 == 0) ? -22.0f : 22.0f;    // Exactly at the left edge (-22) OR right edge (+22)
        spawnY = (rand() % 40) - 20.0f;                 // Random Y anywhere from -20 to 20
    }
      
    // Algorithm for randomizing type of enemy
    std::string randName;
    int choice = rand() % enemyNames.size();
    
    randName = enemyNames[choice];
    EnemyInfo info = enemyPowers[randName]; 

    return Enemy(randName, spawnX, spawnY, info.health, info.speed, info.rate, info.damage);
}
