#include <iostream>
using namespace std;

// Declaring function prototypes
void printBoard(char board[]);
bool didPlayerWin(char board[], char turn);

int main()
{
    // Declaring variables
    // char board is the array that is storing a bunch of spaces
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char turn;
    char winner = ' ';
    int move;

    // For-loop to print the board and play the game
    for (int i = 1; i <= 9; i++)
    {
        // Setting the turn variable to switch between X and O
        turn = (i % 2 != 0) ? 'X' : 'O';
        cout << "Turn: " << turn << endl;
        cout << "Select square: ";
        cin >> move;
        // Setting the array to whatever move is enterred by user
        board[move] = turn;
        cout << endl;
        printBoard(board);

        // If a player wins, break the for-loop
        if (didPlayerWin(board, turn))
        {
            winner = turn; 
            break;
        }
    }

    // Once for-loop is broken, cout that the game is over
    cout << "GAME OVER!" << endl;

    // If there has not been a winner, cout that the game is a draw
    // and terminate the program
    if (winner == ' ')
    {
        cout << "It's a draw!" << endl;
        return 0;
    }

    // If there was a winner, cout who the winner was and terminate
    // the program
    cout << "The winner is: " << winner << "!" << endl;

    return 0;
}

// Function used for printing the board using an array
void printBoard(char board[])
{
    cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
    cout << "-+-+-" << endl;
    cout << board[3] << "|" << board[4] << "|" << board[5] << endl;
    cout << "-+-+-" << endl;
    cout << board[6] << "|" << board[7] << "|" << board[8] << endl;
    cout << endl;
}

// Function that checks for a winner every time the for-loo
bool didPlayerWin(char board[], char turn)
{
    if (board[0] == turn && board[1] == turn && board[2] == turn)
    {
        return true;
    }
    else if (board[0] == turn && board[3] == turn && board[6] == turn)
    {
        return true;
    }
    else if (board[0] == turn && board[4] == turn && board[8] == turn)
    {
        return true;
    }
    else if (board[3] == turn && board[4] == turn && board[5] == turn)
    {
        return true;
    }
    else if (board[1] == turn && board[4] == turn && board[7] == turn)
    {
        return true;
    }
    else if (board[6] == turn && board[4] == turn && board[2] == turn)
    {
        return true;
    }
    else if (board[6] == turn && board[7] == turn && board[8] == turn)
    {
        return true;
    }
    else if (board[2] == turn && board[5] == turn && board[8] == turn)
    {
        return true;
    }
    else
    {
        return false;
    }
}