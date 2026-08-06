#include <SFML/Graphics.hpp>

int main() {
    // 1. Create the physical window (Width, Height, Title)
    sf::RenderWindow window(sf::VideoMode(800, 600), "My First SFML Window!");

    // 2. The Graphical Game Loop (Runs thousands of times a second)
    while (window.isOpen()) {
        
        // 3. Check for inputs (like clicking the 'X' button to close the game)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // 4. Draw the frame!
        window.clear(sf::Color::Blue); // Wipe the screen clean with Blue paint
        window.display();              // Push the painted frame to the monitor
    }

    return 0;
}