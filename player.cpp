#include "player.h"
#include <iostream>
#include <unordered_map>

Player::Player(gun mygun ): getGun(mygun) { 

    x = 0.0f;
    y = 0.0f;
    focusPoints = 0;
    level = 1;

}

void Player::move(char dir){


    if (dir == 'w') y+= 1.0f;
    if (dir == 's') y-= 1.0f;
    if (dir == 'd') x+= 1.0f;
    if (dir == 'a') x-= 1.0f;

    std::cout << "PLayer moved to coordinate ("<< x << "," << y << ")" << std::endl;

}

void Player::gunLevel(){

    
    struct GunInfo {
        float speed;     // How fast the bullet travels
        int damage;      // Health removed per hit
        float fireRate;  // Cooldown timer in seconds   
      
    };

    static std::unordered_map<std::string, GunInfo> gunDictionary = {

        {"Pistol",{1.5f,25,0.4f}},  
        {"Assault Rifle",{2.5f,15,0.15f}}, 
        {"Hunting Rifle",{5.0f,100,1.5f}},  
        {"Machine Gun",{2.0f,8,0.05f}}  
    };


    if(level == 1){

        GunInfo info = gunDictionary["Pistol"];
        getGun = gun("Pistol",info.fireRate, info.damage,info.speed);

    }
    else if (level ==2){

        GunInfo info = gunDictionary["Assault Rifle"];
        getGun = gun("Assault Rifle",info.fireRate, info.damage,info.speed);

    }
    else if (level ==3){

        GunInfo info = gunDictionary["Hunting Rifle"];
        getGun = gun("Hunting Rifle",info.fireRate, info.damage,info.speed);

    }
    else if (level ==4){

        GunInfo info = gunDictionary["Machine Gun"];
        getGun = gun("Machine Gun",info.fireRate, info.damage,info.speed);

    }

}