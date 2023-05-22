#include <iostream>

class TicTacToe
{
public:
    char board[3][3];
    char currentPlayer;
    bool gameover;

public:
    TicTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '-';
            }
        }

        currentPlayer = 'X';
        gameover = false;
    }

    void printBoard() const
    {
        // Print the game board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << board[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    bool GameOver() const
    {
        return gameover;
    }

    void makeMove(int row, int col)
    {
        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-')
        {
            std::cout << "Invalid move! Try again." << std::endl;
            return;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer))
        {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            gameover = true;
            return;
        }

        if (checkDraw())
        {
            std::cout << "It's a draw!" << std::endl;
            gameover = true;
            return;
        }

        // Switches to the next player after the first players move
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

private:
    bool checkWin(char player) const
    {
        // This is here to check to see if there is a horizontal win on the board
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            {
                return true;
            }
        }

        // This is here to check to see if there is a vertical win on the board
        for (int j = 0; j < 3; j++)
        {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            {
                return true;
            }
        }

        // This is here to check to see if there is a diagonal win on the board
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        {
            return true;
        }

        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            return true;
        }

        return false;
    }

    bool checkDraw() const
    {
        // Check if all cells are occupied
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    TicTacToe game;

    while (!game.GameOver())
    {
        int row, col;

        std::cout << "Player " << game.currentPlayer << "'s turn." << std::endl;
        game.printBoard();
        std::cout << "Enter the row (0-2): 0 being 1: ";
        std::cin >> row;
        std::cout << "Enter the column (0-2) 0 being 1: ";
        std::cin >> col;

        game.makeMove(row, col);
        std::cout << std::endl;
    }

    return 0;
}
