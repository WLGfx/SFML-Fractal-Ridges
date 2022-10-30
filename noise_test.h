#include <SFML/Graphics.hpp>
#include "FastNoiseLite.h"

class NoiseTest {
public:
    NoiseTest(sf::RenderWindow *window);

    void update();
    void draw();

private:
    sf::RenderWindow *window;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2u windowSize;
    sf::Clock clock;
    float delta = 0.0f;
    sf::Text text;
    sf::Font font;

    FastNoiseLite noise;

    void texture_noise();
    float zoffset = 0.0f;
    float scale = 1.0f;
};