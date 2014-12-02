#include "main.h"
#include "wrappers.h"

int game(sf::RenderWindow *window)
{
    //Sets mouse position at start
    sf::Mouse::setPosition(sf::Vector2i(WIDTH/2, HEIGHT/2), *window);
    //Sets up the timer and round counter
    int roundCount = 0;
    //Generates the shape
    ShapeWrapper circle;
    circle.setSize(sf::Vector2f(50, 50));
    circle.setPosition(rand()%(WIDTH - 71), rand()%(HEIGHT - 71));

    while (1) {
        //Checks all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                //Handles window close
                case sf::Event::Closed:
                    window->close();
                    return 1;
                    break;

                //Handles mouse events
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (circle.checkShape(window)) {
                            circle.setPosition(rand()%(WIDTH - 71), rand()%(HEIGHT - 71));
                            roundCount++;
                            if (roundCount > 9)
                                return 0;
                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        return 2;
                    }
                    break;

                //Handles keyboard events
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window->close();
                        return 1;
                    }
                    break;

                //If there are no events
                default:
                    break;
            }
        }

        //Puts stuff on the screen
        window->clear(sf::Color::Blue);
        window->draw(circle);
        window->display();
    }

    return 0;
}