#include "Cell.h"
#include "Grid.h"
#include <iostream>

// Set state
void Cell::setAlive(bool state)
{
    is_alive = state;
}

// Check current state
bool Cell::isAliveState()
{
    return is_alive;
}

bool Grid::areAllCellsDead(int rows, int columns)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (board[i][j].isAliveState()) {
                // Found a live cell
                return false;
            }
        }
    }
    return true;
}

bool Grid::checkForBlock(int rows, int columns, Grid board)
{
    // Check for each possible 2x2 grid
    for (int i = 0; i < rows - 3; ++i)
    {
        for (int j = 0; j < columns - 3; ++j)
        {
            bool cell1 = board[i + 1][j + 1].isAliveState();
            bool cell2 = board[i + 2][j + 1].isAliveState();
            bool cell3 = board[i + 1][j + 2].isAliveState();
            bool cell4 = board[i + 2][j + 2].isAliveState();

            bool dead_cell_1 = board[i][j].isAliveState();
            bool dead_cell_2 = board[i + 1][j].isAliveState();
            bool dead_cell_3 = board[i + 2][j].isAliveState();
            bool dead_cell_4 = board[i + 3][j].isAliveState();

            bool dead_cell_5 = board[i][j + 1].isAliveState();
            bool dead_cell_6 = board[i + 3][j + 1].isAliveState();

            bool dead_cell_7 = board[i][j + 2].isAliveState();
            bool dead_cell_8 = board[i + 3][j + 2].isAliveState();

            bool dead_cell_9 = board[i][j + 3].isAliveState();
            bool dead_cell_10 = board[i + 1][j + 3].isAliveState();
            bool dead_cell_11 = board[i + 1][j + 3].isAliveState();
            bool dead_cell_12 = board[i + 3][j + 3].isAliveState();


            // Check the 2x2 grid
            if (cell1 && cell2 && cell3 && cell4 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12)
            {
                // Found a matching 2x2 grid
                return true;
            }
        }
    }
    return false;
}

bool Grid::checkForBeehive(int rows, int columns, Grid board)
{
    for (int i = 0; i < rows - 5; ++i)
    {
        for (int j = 0; j < columns - 4; ++j)
        {
            bool cell1 = board[i + 2][j + 1].isAliveState();
            bool cell2 = board[i + 3][j + 1].isAliveState();
            bool cell3 = board[i + 1][j + 2].isAliveState();
            bool cell4 = board[i + 4][j + 2].isAliveState();
            bool cell5 = board[i + 2][j + 3].isAliveState();
            bool cell6 = board[i + 3][j + 3].isAliveState();


            bool dead_cell_1 = board[i][j].isAliveState();
            bool dead_cell_2 = board[i + 1][j].isAliveState();
            bool dead_cell_3 = board[i + 2][j].isAliveState();
            bool dead_cell_4 = board[i + 3][j].isAliveState();
            bool dead_cell_5 = board[i + 4][j].isAliveState();
            bool dead_cell_6 = board[i + 5][j].isAliveState();

            bool dead_cell_7 = board[i][j + 1].isAliveState();
            bool dead_cell_8 = board[i + 1][j + 1].isAliveState();
            bool dead_cell_9 = board[i + 4][j + 1].isAliveState();
            bool dead_cell_10 = board[i + 5][j + 1].isAliveState();

            bool dead_cell_11 = board[i][j + 2].isAliveState();
            bool dead_cell_12 = board[i + 2][j + 2].isAliveState();
            bool dead_cell_13 = board[i + 3][j + 2].isAliveState();
            bool dead_cell_14 = board[i + 5][j + 2].isAliveState();

            bool dead_cell_15 = board[i][j + 3].isAliveState();
            bool dead_cell_16 = board[i + 1][j + 3].isAliveState();
            bool dead_cell_17 = board[i + 4][j + 3].isAliveState();
            bool dead_cell_18 = board[i + 5][j + 3].isAliveState();

            bool dead_cell_19 = board[i][j + 4].isAliveState();
            bool dead_cell_20 = board[i + 1][j + 4].isAliveState();
            bool dead_cell_21 = board[i + 2][j + 4].isAliveState();
            bool dead_cell_22 = board[i + 3][j + 4].isAliveState();
            bool dead_cell_23 = board[i + 4][j + 4].isAliveState();
            bool dead_cell_24 = board[i + 5][j + 4].isAliveState();

            if (cell1 && cell2 && cell3 && cell4 && cell5 && cell6 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12 && !dead_cell_13 && !dead_cell_14 && !dead_cell_15 && !dead_cell_16 && !dead_cell_17 && !dead_cell_18 && !dead_cell_19 && !dead_cell_20 && !dead_cell_21 && !dead_cell_22 && !dead_cell_23 && !dead_cell_24)
            {
                // Found a beehive
                return true;
            }
        }
    }
    return false;

}

bool Grid::checkForBlinker(int rows, int columns, Grid board)
{

    // Vertical Orientation
    for (int x = 0; x < rows - 2; x++)
    {
        for (int y = 0; y < columns - 4; y++)
        {

            bool cell1 = board[x + 1][y + 1].isAliveState();
            bool cell2 = board[x + 1][y + 2].isAliveState();
            bool cell3 = board[x + 1][y + 3].isAliveState();

            bool dead_cell_1 = board[x][y].isAliveState();
            bool dead_cell_2 = board[x + 1][y].isAliveState();
            bool dead_cell_3 = board[x + 2][y].isAliveState();
            bool dead_cell_4 = board[x][y + 1].isAliveState();
            bool dead_cell_5 = board[x + 2][y + 1].isAliveState();
            bool dead_cell_6 = board[x][y + 2].isAliveState();
            bool dead_cell_7 = board[x + 2][y + 2].isAliveState();
            bool dead_cell_8 = board[x][y + 3].isAliveState();
            bool dead_cell_9 = board[x + 2][y + 3].isAliveState();
            bool dead_cell_10 = board[x][y + 4].isAliveState();
            bool dead_cell_11 = board[x + 1][y + 4].isAliveState();
            bool dead_cell_12 = board[x + 2][y + 4].isAliveState();



            if (cell1 && cell2 && cell3 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12)
            {
                return true;
            }
        }
    }

    // Horizontal Orientation
    for (int x = 0; x < rows - 4; x++)
    {
        for (int y = 0; y < columns - 2; y++)
        {

            bool cell1 = board[x + 1][y + 1].isAliveState();
            bool cell2 = board[x + 2][y + 1].isAliveState();
            bool cell3 = board[x + 3][y + 1].isAliveState();

            bool dead_cell_1 = board[x][y].isAliveState();
            bool dead_cell_2 = board[x + 1][y].isAliveState();
            bool dead_cell_3 = board[x + 2][y].isAliveState();
            bool dead_cell_4 = board[x + 3][y].isAliveState();
            bool dead_cell_5 = board[x + 4][y].isAliveState();
            bool dead_cell_6 = board[x][y + 1].isAliveState();
            bool dead_cell_7 = board[x + 4][y + 1].isAliveState();
            bool dead_cell_8 = board[x][y + 2].isAliveState();
            bool dead_cell_9 = board[x + 1][y + 2].isAliveState();
            bool dead_cell_10 = board[x + 2][y + 2].isAliveState();
            bool dead_cell_11 = board[x + 3][y + 2].isAliveState();
            bool dead_cell_12 = board[x + 4][y + 2].isAliveState();

            if (cell1 && cell2 && cell3 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12)
            {
                return true;
            }
        }
    }

    return false; // No blinker found
}

bool Grid::checkForToad(int rows, int columns, Grid board)
{
    for (int x = 0; x < rows - 3; x++)
    {
        for (int y = 0; y < columns - 5; y++)
        {
            // Toad option 1 

            bool cell1 = board[x + 1][y + 1].isAliveState();
            bool cell2 = board[x + 1][y + 2].isAliveState();
            bool cell3 = board[x + 2][y + 2].isAliveState();
            bool cell4 = board[x + 1][y + 3].isAliveState();
            bool cell5 = board[x + 2][y + 3].isAliveState();
            bool cell6 = board[x + 2][y + 4].isAliveState();


            bool dead_cell_1 = board[x][y].isAliveState();
            bool dead_cell_2 = board[x + 1][y].isAliveState();
            bool dead_cell_3 = board[x + 2][y].isAliveState();
            bool dead_cell_4 = board[x + 3][y].isAliveState();

            bool dead_cell_5 = board[x][y + 1].isAliveState();
            bool dead_cell_6 = board[x + 2][y + 1].isAliveState();
            bool dead_cell_7 = board[x + 3][y + 1].isAliveState();

            bool dead_cell_8 = board[x][y + 2].isAliveState();
            bool dead_cell_9 = board[x + 3][y + 2].isAliveState();

            bool dead_cell_10 = board[x][y + 3].isAliveState();
            bool dead_cell_11 = board[x + 3][y + 3].isAliveState();

            bool dead_cell_12 = board[x][y + 4].isAliveState();
            bool dead_cell_13 = board[x + 1][y + 4].isAliveState();
            bool dead_cell_14 = board[x + 3][y + 4].isAliveState();

            bool dead_cell_15 = board[x][y + 5].isAliveState();
            bool dead_cell_16 = board[x + 1][y + 5].isAliveState();
            bool dead_cell_17 = board[x + 2][y + 5].isAliveState();
            bool dead_cell_18 = board[x + 3][y + 5].isAliveState();

            if (cell1 && cell2 && cell3 && cell4 && cell5 && cell6 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12 && !dead_cell_13 && !dead_cell_14 && !dead_cell_15 && !dead_cell_16 && !dead_cell_17 && !dead_cell_18)
            {
                return true;
            }
        }
    }

    for (int x = 0; x < rows - 5; x++)
    {
        for (int y = 0; y < columns - 5; y++)
        {
            // Toad option 2 

            bool cell1 = board[x + 2][y + 1].isAliveState();
            bool cell2 = board[x + 3][y + 1].isAliveState();
            bool cell3 = board[x + 1][y + 2].isAliveState();
            bool cell4 = board[x + 4][y + 3].isAliveState();
            bool cell5 = board[x + 2][y + 4].isAliveState();
            bool cell6 = board[x + 3][y + 4].isAliveState();

            bool dead_cell_1 = board[x][y].isAliveState();
            bool dead_cell_2 = board[x + 1][y].isAliveState();
            bool dead_cell_3 = board[x + 2][y].isAliveState();
            bool dead_cell_4 = board[x + 3][y].isAliveState();
            bool dead_cell_5 = board[x + 4][y].isAliveState();
            bool dead_cell_6 = board[x + 5][y].isAliveState();

            bool dead_cell_7 = board[x][y + 1].isAliveState();
            bool dead_cell_8 = board[x + 1][y + 1].isAliveState();
            bool dead_cell_9 = board[x + 4][y + 1].isAliveState();
            bool dead_cell_10 = board[x + 5][y + 1].isAliveState();

            bool dead_cell_11 = board[x][y + 2].isAliveState();
            bool dead_cell_12 = board[x + 2][y + 2].isAliveState();
            bool dead_cell_13 = board[x + 3][y + 2].isAliveState();
            bool dead_cell_14 = board[x + 4][y + 2].isAliveState();
            bool dead_cell_15 = board[x + 5][y + 2].isAliveState();

            bool dead_cell_16 = board[x][y + 3].isAliveState();
            bool dead_cell_17 = board[x + 1][y + 3].isAliveState();
            bool dead_cell_18 = board[x + 2][y + 3].isAliveState();
            bool dead_cell_19 = board[x + 3][y + 3].isAliveState();
            bool dead_cell_20 = board[x + 5][y + 3].isAliveState();

            bool dead_cell_21 = board[x][y + 4].isAliveState();
            bool dead_cell_22 = board[x + 1][y + 4].isAliveState();
            bool dead_cell_23 = board[x + 4][y + 4].isAliveState();
            bool dead_cell_24 = board[x + 5][y + 4].isAliveState();

            bool dead_cell_25 = board[x][y + 5].isAliveState();
            bool dead_cell_26 = board[x + 1][y + 5].isAliveState();
            bool dead_cell_27 = board[x + 2][y + 5].isAliveState();
            bool dead_cell_28 = board[x + 3][y + 5].isAliveState();
            bool dead_cell_29 = board[x + 4][y + 5].isAliveState();
            bool dead_cell_30 = board[x + 5][y + 5].isAliveState();


            if (cell1 && cell2 && cell3 && cell4 && cell5 && cell6 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12 && !dead_cell_13 && !dead_cell_14 && !dead_cell_15 && !dead_cell_16 && !dead_cell_17 && !dead_cell_18 && !dead_cell_19 && !dead_cell_20 && !dead_cell_21 && !dead_cell_22 && !dead_cell_23 && !dead_cell_24 && !dead_cell_25 && !dead_cell_26 && !dead_cell_27 && !dead_cell_28 && !dead_cell_29 && !dead_cell_30)
            {
                return true;
            }
        }
    }
    return false;
}

bool Grid::checkForGlider(int rows, int columns, Grid board)
{
    for (int x = 0; x < rows - 4; x++)
    {
        for (int y = 0; y < columns - 4; y++)
        {
            // Glider shape 1
            bool cell1 = board[x + 1][y + 1].isAliveState();
            bool cell2 = board[x + 2][y + 2].isAliveState();
            bool cell3 = board[x + 3][y + 2].isAliveState();
            bool cell4 = board[x + 1][y + 3].isAliveState();
            bool cell5 = board[x + 2][y + 3].isAliveState();

            bool dead_cell_1 = board[x][y].isAliveState();
            bool dead_cell_2 = board[x + 1][y].isAliveState();
            bool dead_cell_3 = board[x + 2][y].isAliveState();
            bool dead_cell_4 = board[x + 3][y].isAliveState();
            bool dead_cell_5 = board[x + 4][y].isAliveState();

            bool dead_cell_6 = board[x][y + 1].isAliveState();
            bool dead_cell_7 = board[x + 2][y + 1].isAliveState();
            bool dead_cell_8 = board[x + 3][y + 1].isAliveState();
            bool dead_cell_9 = board[x + 4][y + 1].isAliveState();

            bool dead_cell_10 = board[x][y + 2].isAliveState();
            bool dead_cell_11 = board[x + 1][y + 2].isAliveState();
            bool dead_cell_12 = board[x + 4][y + 2].isAliveState();

            bool dead_cell_13 = board[x][y + 3].isAliveState();
            bool dead_cell_14 = board[x + 3][y + 3].isAliveState();
            bool dead_cell_15 = board[x + 4][y + 3].isAliveState();

            bool dead_cell_16 = board[x][y + 4].isAliveState();
            bool dead_cell_17 = board[x + 1][y + 4].isAliveState();
            bool dead_cell_18 = board[x + 2][y + 4].isAliveState();
            bool dead_cell_19 = board[x + 3][y + 4].isAliveState();
            bool dead_cell_20 = board[x + 4][y + 4].isAliveState();

            if (cell1 && cell2 && cell3 && cell4 && cell5 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12 && !dead_cell_13 && !dead_cell_14 && !dead_cell_15 && !dead_cell_16 && !dead_cell_17 && !dead_cell_18 && !dead_cell_19 && !dead_cell_20)
            {
                return true;
            }
        }
    }
    for (int x = 0; x < rows - 4; x++)
    {
        for (int y = 0; y < columns - 4; y++)
        {
            // Glider shape 2
            bool cell1 = board[x + 1][y + 2].isAliveState();
            bool cell2 = board[x + 3][y + 1].isAliveState();
            bool cell3 = board[x + 3][y + 2].isAliveState();
            bool cell4 = board[x + 2][y + 3].isAliveState();
            bool cell5 = board[x + 3][y + 3].isAliveState();


            bool dead_cell_1 = board[x][y].isAliveState();
            bool dead_cell_2 = board[x + 1][y].isAliveState();
            bool dead_cell_3 = board[x + 2][y].isAliveState();
            bool dead_cell_4 = board[x + 3][y].isAliveState();
            bool dead_cell_5 = board[x + 4][y].isAliveState();

            bool dead_cell_6 = board[x][y + 1].isAliveState();
            bool dead_cell_7 = board[x + 1][y + 1].isAliveState();
            bool dead_cell_8 = board[x + 2][y + 1].isAliveState();
            bool dead_cell_9 = board[x + 4][y + 1].isAliveState();

            bool dead_cell_10 = board[x][y + 2].isAliveState();
            bool dead_cell_11 = board[x + 2][y + 2].isAliveState();
            bool dead_cell_12 = board[x + 4][y + 2].isAliveState();

            bool dead_cell_13 = board[x][y + 3].isAliveState();
            bool dead_cell_14 = board[x + 1][y + 3].isAliveState();
            bool dead_cell_15 = board[x + 4][y + 3].isAliveState();

            bool dead_cell_16 = board[x][y + 4].isAliveState();
            bool dead_cell_17 = board[x + 1][y + 4].isAliveState();
            bool dead_cell_18 = board[x + 2][y + 4].isAliveState();
            bool dead_cell_19 = board[x + 3][y + 4].isAliveState();
            bool dead_cell_20 = board[x + 4][y + 4].isAliveState();


            if (cell1 && cell2 && cell3 && cell4 && cell5 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12 && !dead_cell_13 && !dead_cell_14 && !dead_cell_15 && !dead_cell_16 && !dead_cell_17 && !dead_cell_18 && !dead_cell_19 && !dead_cell_20)
            {
                return true;
            }
        }
    }
    return false;
}

bool Grid::checkForShip(int rows, int columns, Grid board)
{
    for (int x = 0; x < rows - 6; x++)
    {
        for (int y = 0; y < columns - 5; y++)
        {
            bool cell1 = board[x + 1][y + 1].isAliveState();
            bool cell2 = board[x + 4][y + 1].isAliveState();

            bool cell3 = board[x + 5][y + 2].isAliveState();

            bool cell4 = board[x + 1][y + 3].isAliveState();
            bool cell5 = board[x + 5][y + 3].isAliveState();

            bool cell6 = board[x + 2][y + 4].isAliveState();
            bool cell7 = board[x + 3][y + 4].isAliveState();
            bool cell8 = board[x + 4][y + 4].isAliveState();
            bool cell9 = board[x + 5][y + 4].isAliveState();

            bool dead_cell_1 = board[x][y].isAliveState();
            bool dead_cell_2 = board[x + 1][y].isAliveState();
            bool dead_cell_3 = board[x + 2][y].isAliveState();
            bool dead_cell_4 = board[x + 3][y].isAliveState();
            bool dead_cell_5 = board[x + 4][y].isAliveState();
            bool dead_cell_6 = board[x + 5][y].isAliveState();
            bool dead_cell_7 = board[x + 6][y].isAliveState();

            bool dead_cell_8 = board[x][y + 1].isAliveState();
            bool dead_cell_9 = board[x + 2][y + 1].isAliveState();
            bool dead_cell_10 = board[x + 3][y + 1].isAliveState();
            bool dead_cell_11 = board[x + 5][y + 1].isAliveState();
            bool dead_cell_12 = board[x + 6][y + 1].isAliveState();

            bool dead_cell_13 = board[x][y + 2].isAliveState();
            bool dead_cell_14 = board[x + 1][y + 2].isAliveState();
            bool dead_cell_15 = board[x + 2][y + 2].isAliveState();
            bool dead_cell_16 = board[x + 3][y + 2].isAliveState();
            bool dead_cell_17 = board[x + 4][y + 2].isAliveState();
            bool dead_cell_18 = board[x + 6][y + 2].isAliveState();

            bool dead_cell_19 = board[x][y + 3].isAliveState();
            bool dead_cell_20 = board[x + 2][y + 3].isAliveState();
            bool dead_cell_21 = board[x + 3][y + 3].isAliveState();
            bool dead_cell_22 = board[x + 4][y + 3].isAliveState();
            bool dead_cell_23 = board[x + 6][y + 3].isAliveState();

            bool dead_cell_24 = board[x][y + 4].isAliveState();
            bool dead_cell_25 = board[x + 1][y + 4].isAliveState();
            bool dead_cell_26 = board[x + 6][y + 4].isAliveState();

            bool dead_cell_27 = board[x][y + 5].isAliveState();
            bool dead_cell_28 = board[x + 1][y + 5].isAliveState();
            bool dead_cell_29 = board[x + 2][y + 5].isAliveState();
            bool dead_cell_30 = board[x + 3][y + 5].isAliveState();
            bool dead_cell_31 = board[x + 4][y + 5].isAliveState();
            bool dead_cell_32 = board[x + 5][y + 5].isAliveState();
            bool dead_cell_33 = board[x + 6][y + 5].isAliveState();

            if (cell1 && cell2 && cell3 && cell4 && cell5 && cell6 && cell7 && cell8 && cell9 && !dead_cell_1 && !dead_cell_2 && !dead_cell_3 && !dead_cell_4 && !dead_cell_5 && !dead_cell_6 && !dead_cell_7 && !dead_cell_8 && !dead_cell_9 && !dead_cell_10 && !dead_cell_11 && !dead_cell_12 && !dead_cell_13 && !dead_cell_14 && !dead_cell_15 && !dead_cell_16 && !dead_cell_17 && !dead_cell_18 && !dead_cell_19 && !dead_cell_20 && !dead_cell_21 && !dead_cell_22 && !dead_cell_23 && !dead_cell_24 && !dead_cell_25 && !dead_cell_26 && !dead_cell_27 && !dead_cell_28 && !dead_cell_29 && !dead_cell_30 && !dead_cell_31 && !dead_cell_32 && !dead_cell_33)
            {
                return true;
            }
        }
    }
    return false;
}
