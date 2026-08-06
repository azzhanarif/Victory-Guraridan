#include <iostream>
#include "player.h"
#include <cmath>
#include <vector>
#include "bullet.h"
#include "enemy.h"
#include "Plant.h"
#include "fence.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "gun.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

int main() {

    srand(time(0));
 

    GunInfo defaultName = gunDictionary["Pistol"];
    gun defaultWepon("Pistol", defaultName.speed , defaultName.damage, defaultName.fireRate );
    Player hero(defaultWepon);

    sf::RenderWindow window(sf::VideoMode(800,600),"Victory Guardian");
    window.setFramerateLimit(60);

    sf::RectangleShape playerSprite(sf::Vector2f(20.0f, 20.0f)); // a 20x20 green square sprite
    playerSprite.setFillColor(sf::Color::Green);
    playerSprite.setOrigin(10.0f, 10.0f);


    std::vector<Bullet> bullets; //it works like a python list
    std::vector<Enemy> enemies;
    std::vector<Fence> fences;

    int spawnRate = 20; // level 1 enemies spawn rate
    float roundCounter = 0; // counts every 1/60 of a second and keeps track of time passing


    Plant SuccessPlant(100); //created the plant with 100 health

    // -- game loop --

    while (window.isOpen()) {

        // -- checks the level --

        if(roundCounter >= 60 && roundCounter < 120 && hero.level == 1) {
            hero.level++;
            hero.gunLevel();
            spawnRate += 15;
        }
        else if (roundCounter >= 120 && roundCounter < 240 && hero.level == 2) {
            hero.level++;
            hero.gunLevel();
            spawnRate += 15;
        }
        else if (roundCounter >= 240 && roundCounter < 360 && hero.level == 3) {
            hero.level++;
            hero.gunLevel();
            spawnRate += 15;
        }
        else if (roundCounter >= 360 && hero.level == 4) {
            break; 
        }

        char input;
        std::cin >> input;

        // -- walking mechanics --
        hero.move();

        // -- firing mechanics --
        if (input == 'f') {

            float xx;
            float yy;
            std::cout << "Enter the specific direction you want your bullet to go\nEnter x: "; 
            std::cin >> xx;
            std::cout << "Enter y: ";
            std::cin >> yy;
            
            // calculating distance
            float dx = xx - hero.x;
            float dy = yy - hero.y; 

            float distance = sqrt((dx * dx) + (dy * dy));

            dx = dx / distance;
            dy = dy / distance;

            bullets.push_back(Bullet(hero.x,hero.y,dx,dy,hero.getGun.damage,hero.getGun.hitRate,hero.getGun.speed));
        }


        if (input == 'b') { // 3. Build fence input ('b')
            fences.push_back(Fence(hero.x, hero.y));
            std::cout << "Fence placed at (" << hero.x << ", " << hero.y << ")!\n";
        }


        // -- spawming enemy

        if ((rand() % 100) < spawnRate) { //spawn rate
            enemies.push_back(Enemy::spawn());
        }



        // -- updating the bullets --
        for (int i = 0; i < bullets.size(); i++) {

            if (bullets[i].active) {
                bullets[i].update();

                if (bullets[i].x >= 20.0f | bullets[i].y >= 20.0f | bullets[i].x <= -20.0f | bullets[i].y <= -20.0f) { // 20x20 limit
                    bullets[i].active = false;
                }
            }
        }
       // -- fence logic 
        for (size_t i = 0; i < fences.size(); ) {
            if (fences[i].isDestroyed()) {
                fences.erase(fences.begin() + i);
            }
            else {
                i++;
            }
        }

        // -- updating the enemy --

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].update();
        }

        SuccessPlant.updateGrowth(); // Update the growth of the plant
        std::cout << "Plant Status: " << SuccessPlant.getStatus() << std::endl;



        // -- bullets hitting the enemy logic --

        for(int i = 0 ; i < bullets.size() ; i++){
            if(!bullets[i].active) continue;
            for(int j = 0 ; j < enemies.size() ; j++){
                if(!enemies[j].alive) continue;
                //calculate distance between enemy and the bullet
               float disX = enemies[j].x - bullets[i].x;
               float disY = enemies[j].y - bullets[i].y;

               float dis = (disX * disX) + (disY * disY);

                if(dis < 1.0f){ //1.0f is my threshold for hitting the bullet

                  bullets[i].active = false;
                  enemies[j].health -= bullets[i].damage;

                  if(enemies[j].health <= 0){
                    std::cout << enemies[j].name << " Destroyed!\n";
                    enemies[j].alive = false;
                  }
                 break;
               }
            }
        }

        // removing dead eneimies and bullts from the vector array

        bullets.erase(
           std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return !b.active; }),
           bullets.end()
        );

        enemies.erase(
           std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& e) { return !e.alive; }),
            enemies.end()
        );

        roundCounter += 0.0166f; // +1 on every passing 1 second (loop runs 60 times a second)

    }
    

}