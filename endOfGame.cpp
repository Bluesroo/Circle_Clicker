#include "main.h"
#include "wrappers.h"

int endOfGame(sf::RenderWindow *window, clock_t timer) {
    //Setting up the test to be printed
    sf::Font font;
    font.loadFromFile("arial.ttf");

    TextWrapper scoreText;
    scoreText.timeRound(timer, &font);

    TextWrapper endText;
    endText.exitText(&font);

    //Get whether or not someone would like to play again
    while (1) {
        //Event loop that gets whether someone clicked on Yes or No
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                //Handles window close
                case sf::Event::Closed:
                    window->close();
                    break;

                //Handles mouse events
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        return 0;
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

            //Draw stuff
            window->clear(sf::Color::Black);
            window->draw(scoreText);
            window->draw(endText);
            window->display();
        }
    }
}