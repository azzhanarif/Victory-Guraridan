#include "fence.h"

Fence::Fence(float posX, float posY, int hp)
    : x(posX), y(posY), health(hp) {
}

void Fence::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Fence::isDestroyed() const {
    return health <= 0;
}

float Fence::getX() const { return x; }
float Fence::getY() const { return y; }