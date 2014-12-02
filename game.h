//Includes
#include <stdio.h>
#include <SFML/include/SFML/Graphics.hpp>
#include <SFML/include/SFML/Window.hpp>
#include <SFML/include/SFML/System.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>

//Prototypes
void test();
bool checkChoice(sf::CircleShape, sf::CircleShape, sf::RenderWindow *);
int game(sf::RenderWindow *);
int endOfGame(sf::RenderWindow *, clock_t);

//Constants
int const WIDTH = 800;
int const HEIGHT = 600;