#include <string>
#include "noise_test.h"
#include "FastNoiseLite.h"

NoiseTest::NoiseTest(sf::RenderWindow *window) {
    this->window = window;
    windowSize = window->getSize();
    image.create(windowSize.x, windowSize.y, sf::Color::Black);
    texture.create(windowSize.x, windowSize.y);
    texture.setSmooth(true);
    texture.setSrgb(true);
    sprite.setTexture(texture);
    font.loadFromFile("/usr/share/fonts/opentype/noto/NotoSansCJK-Bold.ttc");
    text.setFillColor(sf::Color(255, 255, 255));
    text.setString("Hello world!");
    text.setFont(font);
    text.setCharacterSize(20);
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetFrequency(0.015f);
    noise.SetFractalOctaves(1);
    noise.SetFractalType(FastNoiseLite::FractalType_Ridged);
}

void NoiseTest::update() {
    texture_noise();
}

void NoiseTest::draw() {
    texture.loadFromImage(image);
    window->draw(sprite);

    text.setString("Frame time millis " + std::to_string(int(delta * 1000.0f)));
    window->draw(text);

    delta = clock.restart().asSeconds();
}

void NoiseTest::texture_noise() {
    int r, g, b, c;
    for (uint y = 0; y < windowSize.y; y++) {
        for (uint x = 0; x < windowSize.x; x++) {
            float val = noise.GetNoise((float)x * scale, (float)y * scale, zoffset) * 2.0f - 1.0f;
            c = val * 256.0f;
            if (c < 0) {
                r = 0;
                g = 0;
                b = 192 - ((c >> 2) & 127);
            } else {
                r = c > 255 ? 255 - ((c / 8)): c;
                g = c > 255 ? 255 - ((c / 6)): c;
                b = -c;
            }
            image.setPixel(x, y, sf::Color(r, g, b));
        }
    }
    zoffset += 10.0f * delta;
}