#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>

#include "player.cpp"

class Board
{
    std::array<std::array<Player, 3>, 3> mBoard {};

    public:
        const std::array<std::array<Player, 3>, 3> get() const;
        Player& getPos(int xy);
        void setValue(int pos, const Player &player);
        void reset();
};

#endif