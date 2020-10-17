#include "game_input.hpp"

int GameInput::promptMove()
{
    int move;

    std::cout << "Select an available move: ";

    while(!move)
    {
        if (kbhit())
        {
            move = getch() - 48;
        }
    }

    return move;
}

bool GameInput::promptNewGame()
{
    textcolor(YELLOW);
    std::cout << "Do you want to play again?(y/n): ";
    textcolor(WHITE);
    
    char option;

    do
    {
        if (kbhit()) {
            option = getch();
        }    
    } while (option != 'Y' && option != 'N' && option != 'y' && option != 'n');
    
    return option == 'Y' || option == 'y';
}