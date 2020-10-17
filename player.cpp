#ifndef PLAYER_CPP
#define PLAYER_CPP

struct Player
{
    char symbol;

    bool operator==(const Player &p) const
    {
        return this->symbol == p.symbol;
    }

    bool operator!=(const Player &p) const
    {
        return this->symbol != p.symbol;
    }
};

#endif