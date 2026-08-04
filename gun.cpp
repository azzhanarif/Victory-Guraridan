#include"gun.h"

gun::gun(std::string nm, float spd, float dmg , float fr)
{
    name = nm;
    hitRate = fr; 
    damage = dmg;
    speed = spd;

}

std::unordered_map<std::string, GunInfo> gunDictionary = {
    
    {"Pistol",{1.5f,25,0.4f}},
    {"Assault Rifle",{2.5f,15,0.15f}},
    {"Hunting Rifle",{5.0f,100,1.5f}},
    {"Machine Gun",{2.0f,8,0.05f}}

};
