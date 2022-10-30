#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "noise_test.h"

int main(int argc, const char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "WLGfx Noise Test");
    NoiseTest test(&window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        test.update();
        test.draw();

        window.display();
        usleep(1000);
    }

    return 0;
}