#include "Grid.h"

using namespace std;


Grid::Grid(int ROWS, int COLUMNS)
{
    // Grid setup
    rows = ROWS;
    columns = COLUMNS;

    board = new Cell * [rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Cell[columns];
    }
}

~Grid()
{
    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}

void Grid::randomiseAliveCells(int STARTING_CELL_AMOUNT)
{
    // Use time to have a dynamic seed
    srand(time(0));
    for (int n = 0; n < STARTING_CELL_AMOUNT; ++n) {
        int random_row = rand() % rows;
        int random_col = rand() % columns;

        // Ensure  don't overwrite an existing 'O'
        while (board[random_row][random_col].isAliveState()) {
            random_row = rand() % rows;
            random_col = rand() % columns;
        }

        board[random_row][random_col].setAlive(true);
    }
}

void Grid::printGrid()
{
    for (int i = 0; i < rows; i++)
    {
        cout << ".";
        for (int j = 0; j < columns; j++)
        {
            cout << (board[i][j].isAliveState() ? 'O' : ' ') << ".";
        }
        cout << endl;
    }
}
void Grid::updateGrid() {

    // Will be used to override old board
    Cell** newBoard = new Cell * [rows];
    for (int i = 0; i < rows; i++) {
        newBoard[i] = new Cell[columns];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            // Totals amount of live neighbours
            int aliveNeighbors = countAliveNeighbors(i, j);

            // Checks if the current cell is alive or dead
            if (board[i][j].isAliveState()) 
            {
                // Cell will be alive for next gen if it has 2 or 3 alive neighbours
                newBoard[i][j].setAlive(aliveNeighbors == 2 || aliveNeighbors == 3);
            }
            else 
            {
                // Cell will come alive next gen if it has 3 alive neighburs
                newBoard[i][j].setAlive(aliveNeighbors == 3);
            }
        }
    }

    // Update board
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
        board[i] = newBoard[i];
    }
    delete[] newBoard;
}