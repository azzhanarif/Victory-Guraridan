#include "Plant.h"

Plant::Plant(int health, float posX, float posY)
    : maximumHealth(health), currentHealth(health), growthPct(0.0f), x(posX), y(posY) {
}

void Plant::takeDamage(int damage) {
    currentHealth -= damage;
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}

void Plant::updateGrowth() {
    if (currentHealth > 0) {
        growthPct += 0.01f;
        if (growthPct > 100.0f) {
            growthPct = 100.0f;
        }
    }
    else {
        growthPct = 0.0f;
    }
}

float Plant::getX() const { return x; }
float Plant::getY() const { return y; }
bool Plant::isDead() const { return currentHealth <= 0; }

std::string Plant::getStatus() const {
    return "Health: " + std::to_string(currentHealth) + " | Growth: " + std::to_string(growthPct) + "%";
}