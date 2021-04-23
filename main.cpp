#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

const int HEIGHT = 600;
const int WIDTH = 800;

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "VSelSort");

    sf::Vector2f position;
    
    std::vector<int> vtr;

    sf::Time delayTime = sf::milliseconds(30);
    sf::Clock clock;
    
    int minInd = 0;
    int temp = 0;

    // input
    int n = 400;
    //std::cout << "Enter number of elements: ";
    //std::cin >> n;
    sf::sleep(sf::milliseconds(10000));

    // init array
    for(int i = 0; i < n; i++) {
        vtr.push_back(rand() % 100 + 1);
    }

    // init render
    sf::RectangleShape rect;
    int barW = WIDTH/n;
    int barH = 5;
    rect.setFillColor(sf::Color::Green);
    for(int j = 0; j < n; j++){
        rect.setSize(sf::Vector2f(barW, vtr[j]*barH));
        position.x = j*barW;
        position.y = HEIGHT - vtr[j]*barH;
        rect.setPosition(position);
        window.draw(rect);
        
    }

    window.display();

    
    while (window.isOpen())
    {
        for(int i = 0; i < n; i++) {
            sf::Event e;
            while (window.pollEvent(e))
                if (e.type == sf::Event::Closed)
                    window.close();

            minInd = i;
            
            for(int j = i; j < n; j++){
                if(vtr.at(minInd) > vtr.at(j)){
                    minInd = j;
                }
            }
            temp = vtr.at(minInd);
            vtr.at(minInd) = vtr.at(i);
            vtr.at(i) = temp;
            
            // redraw
            rect.setFillColor(sf::Color::Green);
            for(int j = 0; j < n; j++){
                rect.setSize(sf::Vector2f(barW, vtr[j]*barH));
                position.x = j*barW;
                position.y = HEIGHT - vtr[j]*barH;
                rect.setPosition(position);
                window.draw(rect);
                
            }

            // show values to switch
            rect.setFillColor(sf::Color::Red);

            rect.setSize(sf::Vector2f(barW, vtr[minInd]*barH));
            position.x = minInd*barW;
            position.y = HEIGHT - vtr[minInd]*barH;
            rect.setPosition(position);
            window.draw(rect);

            rect.setSize(sf::Vector2f(barW, vtr[i]*barH));
            position.x = i*barW;
            position.y = HEIGHT - vtr[i]*barH;
            rect.setPosition(position);
            window.draw(rect);

            // refresh
            window.display();
            window.clear();
            sf::sleep(delayTime);

            // revert colors
            rect.setFillColor(sf::Color::Green);
            rect.setSize(sf::Vector2f(barW, vtr[i]*barH));
            position.x = i*barW;
            position.y = HEIGHT - vtr[i]*barH;
            rect.setPosition(position);
            window.draw(rect);

            rect.setSize(sf::Vector2f(barW, vtr[minInd]*barH));
            position.x = minInd*barW;
            position.y = HEIGHT - vtr[minInd]*barH;
            rect.setPosition(position);
            window.draw(rect);

        }

        while(true){
            sf::Event e;
            while (window.pollEvent(e))
                if (e.type == sf::Event::Closed)
                    window.close();
        }
    }
}