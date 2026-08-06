#include "player.h"
#include <iostream>
#include <unordered_map>
#include "gun.h"
#include<SFML/Graphics.hpp>
#include<cmath>


Player::Player(gun mygun ): getGun(mygun) { 

    x = 0.0f;
    y = 0.0f;
    focusPoints = 0;
    level = 1;

}

void Player::move(){

    float dx = 0.0f;
    float dy = 0.0f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dy -= 1.0f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dx -= 1.0f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dy += 1.0f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dx += 1.0f;

    if(dx != 0 || dy != 0){
        float dis = std::sqrt((dx*dx) + (dy*dy));
        dx = dx/dis;
        dy = dy/dis;
    }

    x += dx * 0.15;
    y += dy * 0.15;
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