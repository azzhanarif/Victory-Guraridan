#pragma once
#include <SFML/Graphics.hpp>
class Plant
{
private:
	int currentHealth;
	int maximumHealth;
	float growthPct; 
	sf::CircleShape body; // It SFML Built In Var which is the plant's visual representation
public:
	void draw(sf::RenderWindow& window) {// Render window batata hai window pe draw kro
		// draw the plant on the screen
	}
	void takeDamage(int damage) {
		//detemines the damage taken
	}
	void updateGrowth() {
	
	}
	sf::Vector2f getPosition() {
		// return the position of the plant
	}
	std::string getStatus() {
		// return the status of the plant (e.g. healthy, damaged, dead)
	}
};