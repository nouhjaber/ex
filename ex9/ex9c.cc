#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

const int N = 9; 
int board[N][N];

void userInput();
void printBoard();
bool solveSudoku();
bool isValid(int row, int col, int num);

int main()
{
    userInput();

    if (solveSudoku())
    {
        printBoard();
    }

    return EXIT_SUCCESS;
}

bool isValid(int row, int col, int num)
{
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            return false;

    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(row, col, num))
                    {
                        board[row][col] = num;


                        if (solveSudoku())
                            return true;

                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

void userInput()
{
    int row, col, value;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    while (true)
    {
        cin >> row;
        if (row == -1) break;

        cin >> col >> value;
        if (row >= 0 && row < N && col >= 0 && col < N && value >= 1 && value <= 9)
            board[row][col] = value;
    }
}
