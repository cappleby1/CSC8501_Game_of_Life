#include "Grid.h"
#include <sstream>
#include <fstream>

using namespace std;

void Grid::saveGameToCSV(int rows, int columns)
{
    ofstream file("save_data.csv");

    if (!file)
    {
        cout << "Error no file found";
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            file << board[i][j];
            if (j < columns - 1) {
                file << ","; // Add comma between values
            }
        }
        file << "\n";
    }
    file.close();
}

int Grid::countAliveNeighbours(int x, int y, int rows, int columns) {
    int count = 0;

    // Checks all surrounding cells for alive neighbours
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = x + i, nj = y + j;
            // Check bounds and alive state in a single line
            if (ni >= 0 && ni < rows && nj >= 0 && nj < columns && board[ni][nj].isAliveState()) {
                count++;
            }
        }
    }
    return count;
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
            int aliveNeighbors = countAliveNeighbours(i, j, rows, columns);

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

Grid::~Grid()
{
    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}