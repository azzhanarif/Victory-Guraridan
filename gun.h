#pragma once
#include<iostream>

struct gun
{
    std::string name;
    float hitRate;
    float damage;
    float speed;

    gun(std::string nm, float hr, float dmg, float spd);

};
