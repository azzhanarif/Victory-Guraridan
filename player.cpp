#include "player.h"
#include <iostream>
#include <unordered_map>
#include "gun.h"


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


    if(level == 1){

        GunInfo info = gunDictionary["Pistol"];
        getGun = gun("Pistol",info.speed, info.damage,info.fireRate);

    }
    else if (level ==2){

        GunInfo info = gunDictionary["Assault Rifle"];
        getGun = gun("Assault Rifle",info.speed, info.damage,info.fireRate);

    }
    else if (level ==3){

        GunInfo info = gunDictionary["Hunting Rifle"];
        getGun = gun("Hunting Rifle",info.speed, info.damage,info.fireRate);

    }
    else if (level ==4){

        GunInfo info = gunDictionary["Machine Gun"];
        getGun = gun("Machine Gun",info.speed, info.damage,info.fireRate);

    }
    else{
        return;
    }

}