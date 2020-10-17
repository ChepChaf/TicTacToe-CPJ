#ifndef GAME_INPUT_HPP
#define GAME_INPUT_HPP

#include <conio2.h>
#include <iostream>

class GameInput
{
    public:
        int promptMove();
        bool promptNewGame();
};

#endif