#include "print.hpp"



void printArray(std::vector<int> v, sf::RenderWindow window, int height, int n) {
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Green);

    sf::Vector2f position;
    for(unsigned j = 0; j < n; j++){
        rect.setSize(sf::Vector2f(128, v[j]*50));
        position.x = j*128;
        position.y = height - v[j]*50;
        rect.setPosition(position);
        window.draw(rect);
    }
}