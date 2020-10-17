#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <vector>
#include <array>
#include <algorithm>

#include "board.hpp"
#include "player.cpp"

class TicTacToe
{
    Board *mBoard;
    Player *mCurrentPlayer;
    Player *mWinner;
    
    // Third player is empty to reset board without assigning extra memory
    std::array<Player, 3> mPlayers {};

    bool mRunning { false };

    void resetBoard();

    public:
        bool initEngine();
        void startMatch();
        bool isRunning();
        void makeMove(const int movement);
        const Player &getWinner();
        bool isValidMove(int move) const;
        bool hasWinner();

        const Board& getCurrentBoard() const;
        const std::vector<int> availableMoves() const;
};

#endif