#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>

class ShapeWrapper: public sf::RectangleShape {
public:
    //Checks that the click was inside of the shape
    bool checkShape(sf::RenderWindow *window)
    {
        if (sf::Mouse::getPosition(*window).x >= getPosition().x && sf::Mouse::getPosition(*window).x <= (getPosition().x + 50))
            if (sf::Mouse::getPosition(*window).y >= getPosition().y && sf::Mouse::getPosition(*window).y <= (getPosition().y + 50))
                return true;

    return false;
    }
};

class TextWrapper : public sf::Text {
public:
    void timeRound(clock_t timer, sf::Font *font) {
        clock_t endTime = clock();
        float roundTime = ((endTime - timer) / CLOCKS_PER_SEC);
        std::ostringstream doneTime;
        doneTime << roundTime;
        std::string doneText = ("Your time was: " +doneTime.str()+ " seconds.");

        setString(doneText);
        setFont(*font);
        setCharacterSize(30);
        setStyle(sf::Text::Bold);
        setColor(sf::Color::White);
        setPosition(200, 200);

        return;
    }

    void exitText(sf::Font *font) {
        setString("To exit press Escape.\nIf you'd like to play again click anywhere.");
        setFont(*font);
        setCharacterSize(30);
        setStyle(sf::Text::Bold);
        setColor(sf::Color::White);
        setPosition(75, 400);
    }
};