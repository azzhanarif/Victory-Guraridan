#pragma once    
#include <string>

class Plant {
private:
    int maximumHealth;
    int currentHealth;
    float growthPct;
    float x;
    float y;

public:
    Plant(int health = 100, float posX = 0.0f, float posY = 0.0f);

    void takeDamage(int damage);
    void updateGrowth();

    float getX() const;
    float getY() const;
    bool isDead() const;
    std::string getStatus() const;
    
};