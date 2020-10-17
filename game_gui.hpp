#ifndef GAME_GUI_HPP
#define GAME_GUI_HPP

#include <conio2.h>
#include <iostream>

#include "tic_tac_toe.hpp"
#include "player.cpp"

class GameGUI
{
    public:
        void drawBoard(const TicTacToe &engine);
        void showAvailableMoves(const TicTacToe &engine);
        void showWinner(Player &winner);
        void showDraw();
};

#endif