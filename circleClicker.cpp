#pragma once
#include "stdafx.h"

int main() {
    //Creates the window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");
    //Seeds random
    std::srand(time(NULL));
    //Initialize important variables
    int done = 0;
    clock_t timerStart;

    //Run the program as long as the window is open
    while (window.isOpen() && done != 1) {
        //Gets time at the start of the game
        timerStart = clock();
        //Game loop
        done = game(&window);

        if (done == 0)
            //Finds out whether the player wants another round
            done = endOfGame(&window, timerStart);
    }

    return 0;
}