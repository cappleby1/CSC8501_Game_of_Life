#include <iostream>
#include "header.h"

using namespace std;

bool checkForBlock(int rows, int columns)
{
    // Check for each possible 2x2 grid
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < columns - 1; ++j) {
            // Check the 2x2 grid
            if (game_board[i][j] == game_board[i][j + 1] &&
                game_board[i][j] == game_board[i + 1][j] &&
                game_board[i][j] == game_board[i + 1][j + 1]) {
                return true; // Found a matching 2x2 grid
            }
        }
    }
    return false;
}
