#include <iostream>
#include "bullet.h"
#include <cmath>

// Notice I changed the parameter names slightly to make them obvious
Bullet::Bullet(float sX, float sY, float dirX, float dirY, float dmg, float fr, float spd) {
    // 1. Current Position (Where the bullet is right now)
    x = sX;
    y = sY;

    // 2. Locked Direction (The trajectory we calculated in main.cpp)
    dx = dirX;
    dy = dirY;

    // 3. Stats
    damage = dmg;
    fireRate = fr;
    speed = spd;
    active = true;
}

void Bullet::update() {
    // We update the CURRENT position (x, y) using the locked direction (dx, dy)
    x += dx * speed;
    y += dy * speed;
}