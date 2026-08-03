#pragma once

class Fence {
private:
    int health;
    float x;
    float y;

public:
    Fence(float posX = 0.0f, float posY = 0.0f, int hp = 100);

    void takeDamage(int damage);
    bool isDestroyed() const;
    float getX() const;
    float getY() const;
};