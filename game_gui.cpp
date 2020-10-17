#include "game_gui.hpp"

void GameGUI::drawBoard(const TicTacToe &engine)
{
    const Board board = engine.getCurrentBoard();
    
    // Start drawing
    clrscr(); // Clear screen
    gotoxy(0,0);
    for(int i = 0; i < 80; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
    
    std::cout << "\tBOARD\n";

    int i = 0;
    for (auto row : board.get())
    {
        gotoxy(10, 3 + i++);
        for (auto col : row)
        {
            std::cout << col.symbol << "|";
        }
        std::cout << "\n";
    }
}

void GameGUI::showAvailableMoves(const TicTacToe &engine)
{
    const std::vector<int> availableMoves = engine.availableMoves();

    gotoxy(45, 2);
    std::cout << "Slots on the Board\n";

    for (int i = 0; i < 3; i++)
    {
        gotoxy(50, 3 + i);
        for (int j = 0; j < 3; j++)
        {
            if (!engine.isValidMove((i*3)+j+1))
            {
                textcolor(RED);
            } else {
                textcolor(WHITE);
            }

            std::cout << (i*3) + j + 1;
            
            textcolor(WHITE);
            std::cout << "|";
        }
        std::cout << "\n";
    }

    for(int i = 0; i < 80; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

void GameGUI::showWinner(Player &winner)
{
    textcolor(GREEN);
    std::cout << "THE WINNER IS: " << winner.symbol << "\n";
    textcolor(WHITE);
}

void GameGUI::showDraw()
{
    textcolor(YELLOW);
    std::cout << "IS A DRAW!\n";
    textcolor(WHITE); 
}