#pragma once
#include<unordered_map>
#include<iostream>

struct GunInfo {
    float speed;
    int damage;
    float fireRate;
};


extern std::unordered_map<std::string, GunInfo> gunDictionary; // external keyword makes this dictionary global

struct gun
{
    std::string name;
    float hitRate;
    float damage;
    float speed;

    gun(std::string nm, float spd, float dmg, float fr);

};
