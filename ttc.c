#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board
char currentPlayer = 'X'; // Starting player

// Function to initialize the board with empty spaces
void initializeBoard() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() 
{
    printf("\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
            {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if the current player has won
int checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) 
        {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) 
    {
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) 
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return 1;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    {
        return 1;
    }

    return 0;
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == ' ') 
            {
                return 0; // If there's an empty space
            }
        }
    }
    return 1; // Board is full
}

// Function to switch players
void switchPlayer() {
    if (currentPlayer == 'X') 
    {
        currentPlayer = 'O';
    } else 
    {
        currentPlayer = 'X';
    }
}

// Function to play the game
void playGame() 
{
    int row, col;
    int gameWon = 0;

    initializeBoard();

    while (!gameWon && !isBoardFull()) {
        printBoard();
        printf("Player %c, enter your move (row [1-3] and column [1-3]): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Convert to 0-based index
        row--;
        col--;

        // Check if the position is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') 
        {
            
            // Make the move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin()) 
            {
                gameWon = 1;
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
            } 
            else 
            {
                // Switch players
                switchPlayer();
            }
        } 
        else 
        {
            printf("Invalid move, try again.\n");
        }
    }

    // If the board is full and no one has won, it's a draw
    if (!gameWon) 
    {
        printBoard();
        printf("It's a draw!\n");
    }
}

int main() {
    playGame();
    return 0;
}
