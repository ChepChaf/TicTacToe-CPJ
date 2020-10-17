#include "board.hpp"

Player& Board::getPos(int xy)
{
    return mBoard[(xy-1) / 3][(xy-1) % 3];
};

void Board::setValue(int pos, const Player &player)
{
    if (pos < 0 || pos > 9)
        return;

    mBoard[(pos-1) / 3][(pos-1) % 3] = player;
};

const std::array<std::array<Player, 3>, 3> Board::get() const
{
    return mBoard;
}