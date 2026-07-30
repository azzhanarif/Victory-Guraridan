#include "player.h"
#include <iostream>

Player::Player(){ // constructor

    x = 0.0f;
    y = 0.0f;
    focusPoints = 0;

}

void Player::move(char dir){

    if (dir == 'w') y+= 1.0f;
    if (dir == 's') y-= 1.0f;
    if (dir == 'd') x+= 1.0f;
    if (dir == 'a') x-= 1.0f;

    std::cout << "PLayer moved to coordinate ("<< x << "," << y << ")" << std::endl;

}
