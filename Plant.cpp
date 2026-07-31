#include "Plant.h";

Plant::Plant(int maxHealth) {
	maximumHealth = maxHealth;
	currentHealth = maxHealth;
	growthPct = 0.0f;
	body.setRadius(10.0f); 
	body.setFillColor(sf::Color::Green); 
	int windowWidth = 800; // we can change this to the actual widht
	int windowHeight = 600;
	body.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
}

void Plant::draw(sf::RenderWindow& window) {
	window.draw(body);  // ye sb built in hai game loop will run it
}

void Plant::takeDamage(int damage) {
	currentHealth -= damage;
	if (currentHealth < 0) {
		currentHealth = 0;
	}
}

void Plant::updateGrowth() {
	//working on it ismay gndi logic hai frames wali :( // Abhee beshak sfml use na kar, logic banjaye uske baad end pai karlengay araam sai 
}

sf::Vector2f Plant::getPosition() {   // this is also built in sfml to return cord
	return body.getPosition();
}

std::string Plant::getStatus() {
	if (currentHealth == 0) {
		return "dead";
	}
	else if (currentHealth < maximumHealth / 2) {
		return "damaged";
	}
	else {
		return "healthy";
	}
}