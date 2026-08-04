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

int main() {

    srand(time(0));

    Player hero;
    std::vector<Bullet> bullets; //it works like a python list
    std::vector<Enemy> enemies;
    std::vector<Fence> fences;

    Plant SuccessPlant(100); //created the plant with 100 health

    // -- game loop --

    while (true) {

        char input;
        std::cin >> input;

        if (input == 'q') break;

        if (input == 'w' | input == 'a' | input == 's' | input == 'd') {
            hero.move(input);
        }
        else if (input == 'l') bullets.push_back(Bullet(hero.x, hero.y, 1.0f, 0.0f)); // everytime a bullet is created it is stored into vector bullets
        else if (input == 'i') bullets.push_back(Bullet(hero.x, hero.y, 0.0f, 1.0f));
        else if (input == 'k') bullets.push_back(Bullet(hero.x, hero.y, 0.0f, -1.0f));
        else if (input == 'j') bullets.push_back(Bullet(hero.x, hero.y, -1.0f, 0.0f));
        else if (input == 'b') { // 3. Build fence input ('b')
            fences.push_back(Fence(hero.x, hero.y));
            std::cout << "Fence placed at (" << hero.x << ", " << hero.y << ")!\n";
        }
        else if (input == 'f') {

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

            bullets.push_back(Bullet(hero.x,hero.y,dx,dy));// ERROR ======>>> need to add damage and speedRate parameters here
        }

        // -- spawming enemy

        if ((rand() % 100) < 40) { // 40% spawn rate
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
                  enemies[j].health -= 50; // -= bullets[i].damage

                  if(enemies[j].health <= 0){
                    std::cout << enemies[j].name << " Destroyed!\n";
                    enemies[i].alive = false;
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

    }
    

}