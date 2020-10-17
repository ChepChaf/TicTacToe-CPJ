#include "tic_tac_toe.hpp"

#ifdef DEBUG
#include<iostream>
#endif

bool TicTacToe::initEngine()
{
    #ifdef DEBUG
        std::cout << "Initing engine\n";
    #endif

    mPlayers[0] = Player{'X'};
    mPlayers[1] = Player{'O'};

    // Extra Player for empty slots
    mPlayers[2] = Player { '-' };
    
    mBoard = new Board();

    return true;
}

void TicTacToe::startMatch()
{
    resetBoard();
    mCurrentPlayer = &mPlayers[0];
    mWinner = nullptr;

    mRunning = true;
}

bool TicTacToe::isRunning()
{
    return mRunning;
}

bool TicTacToe::isValidMove(int move) const
{
    std::vector<int> moves = availableMoves();

    int count = std::count(moves.begin(), moves.end(), move);

    return count > 0;
}

void TicTacToe::makeMove(int move)
{
    #ifdef DEBUG
        std::cout << "Moving: " << move << "\n";
    #endif
    mBoard->setValue(move, *mCurrentPlayer);
    
    mCurrentPlayer = mCurrentPlayer->symbol == mPlayers[0].symbol ? &mPlayers[1] : &mPlayers[0];
}

void TicTacToe::resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mBoard->setValue((i*3) + j+1, mPlayers[2]); // Empty player
        }
    }
}

const std::vector<int> TicTacToe::availableMoves() const
{
    std::vector<int> moves = std::vector<int>();

    std::array<std::array<Player, 3>, 3> board = mBoard->get();

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[i][j] == mPlayers[2])
            {
                moves.push_back((i*3) + j +1);
            }
        }
    }

    return moves;
}

const Board& TicTacToe::getCurrentBoard() const
{
    return *mBoard;
}

const Player& TicTacToe::getWinner()
{
    if (mWinner != nullptr)
    {
        return *mWinner;
    }

    for (int i = 0; i < 3; i++)
    {
        // Horizontal
        if (mBoard->getPos((i*3)+1) != mPlayers[2] && mBoard->getPos((i*3)+1) == mBoard->getPos((i*3)+1 +1) 
            && mBoard->getPos((i*3)+1) == mBoard->getPos((i*3)+1 + 2))
        {
            return mBoard->getPos((i*3)+1);
        }

        // Vertical
        if ((mBoard->getPos(i) != mPlayers[2]) && (mBoard->getPos(i) == mBoard->getPos(i+3)) 
            && (mBoard->getPos(i) == mBoard->getPos(i+6)))
        {
            return mBoard->getPos(i);
        }
    }

    // Diagonal
    if (mBoard->getPos(1) != mPlayers[2] && ((mBoard->getPos(1) == mBoard->getPos(5) && mBoard->getPos(1) == mBoard->getPos(9))))
    {
        return mBoard->getPos(1);
    }
    if (mBoard->getPos(3) != mPlayers[2] && (mBoard->getPos(3) == mBoard->getPos(5)) && (mBoard->getPos(3) == mBoard->getPos(7)))
    {
        return mBoard->getPos(3);
    }

    return mPlayers[2];
}

bool TicTacToe::hasWinner()
{
    const Player winner = getWinner();

    if (winner != mPlayers[2])
    {
        mWinner = new Player { winner.symbol };
        mRunning = false;

        return true;
    }

    if (availableMoves().size() == 0)
    {
        mRunning = false;
    }

    return false;
}