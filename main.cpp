#include <iostream>

#include "tic_tac_toe.hpp"
#include "game_gui.hpp"
#include "game_input.hpp"
#include "player.cpp"

int main()
{
    TicTacToe *engine { new TicTacToe() };
    GameGUI *gameGUI { new GameGUI() };
    GameInput *gameInput { new GameInput() };

    if (engine->initEngine())
    {
        engine->startMatch();

        while(engine->isRunning())
        {
            int move;

            do
            {
                gameGUI->drawBoard(*engine);
                gameGUI->showAvailableMoves(*engine);
                
                move = gameInput->promptMove();
            } while (!engine->isValidMove(move));
            
            engine->makeMove(move);

            if (engine->hasWinner())
            {
                Player winner = engine->getWinner();
                gameGUI->showWinner(winner);
                bool newGame = gameInput->promptNewGame();

                if (newGame)
                {
                    engine->startMatch();
                }
            }
            if (engine->availableMoves().size() == 0)
            {
                gameGUI->showDraw();
                bool newGame = gameInput->promptNewGame();

                if (newGame)
                {
                    engine->startMatch();
                }
            }
        }
    }

    delete engine;
    engine = nullptr;

    delete gameGUI;
    gameGUI = nullptr;

    delete gameInput;
    gameInput = nullptr;

    return 0;
}