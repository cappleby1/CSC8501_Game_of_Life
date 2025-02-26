#include "Grid.h"
#include <sstream>
#include <fstream>

using namespace std;

void Grid::saveGameToCSV()
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

void Grid::loadGameFromCSV(int ROWS, Grid game_board)
{
    ifstream file("save_data.csv");
    string line;
    int currentRow = 0;

    while (getline(file, line) && currentRow < ROWS) {
        stringstream ss(line);
        string value;
        int currentColumn = 0;

        // Read values into the grid and set active cells
        while (getline(ss, value, ',')) {
            if (value == "1") {
                game_board.board[currentRow][currentColumn].setAlive(true); // Set cell to active
            }
            currentColumn++;
        }
        currentRow++;
    }
}

int Grid::countAliveNeighbours(int row, int col) {
    int aliveCount = 0;

    // Loop through all 8 neighbors around the current cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Skip the current cell itself
            if (i == 0 && j == 0) continue;

            int neighborRow = row + i;
            int neighborCol = col + j;

            // Check if the neighbor is within bounds
            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < columns) {
                if (board[neighborRow][neighborCol].isAliveState()) {
                    aliveCount++;  // Increment count if the neighbor is alive
                }
            }
        }
    }

    return aliveCount;
}


bool Grid::areAllCellsDead()
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
    // Create a new temporary board to store the next generation
    Cell** newBoard = new Cell * [rows];
    for (int i = 0; i < rows; ++i) {
        newBoard[i] = new Cell[columns];
    }

    // Update each cell based on its neighbors
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int aliveNeighbors = countAliveNeighbours(i, j);  // Count live neighbors

            if (board[i][j].isAliveState()) {
                // Cell is alive: It survives if it has 2 or 3 live neighbors
                newBoard[i][j].setAlive(aliveNeighbors == 2 || aliveNeighbors == 3);
            }
            else {
                // Cell is dead: It comes alive if it has exactly 3 live neighbors
                newBoard[i][j].setAlive(aliveNeighbors == 3);
            }
        }
    }

    // Free the old board and update the board pointer to point to the new board
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
        board[i] = newBoard[i];
    }
    delete[] newBoard;  // Free the temporary new board
}




// With parameters
Grid::Grid(int ROWS, int COLUMNS)
{
    // Grid setup
    rows = ROWS;
    columns = COLUMNS;

    // Allocate memory for the grid
    board = new Cell * [rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Cell[columns];
    }

    // Initialize cells (randomly set them to alive or dead)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            // Randomly set cells to alive or dead
            if (rand() % 2 == 0) {
                board[i][j].setAlive(true);
            }
            else {
                board[i][j].setAlive(false);
            }
        }
    }
}


// Default with no parameters
Grid::Grid() {
    this->rows = 10;    // default number of rows
    this->columns = 10; // default number of columns

    // Allocate memory for the board
    board = new Cell * [rows];
    for (int i = 0; i < rows; ++i) {
        board[i] = new Cell[columns];
    }

    // Initialize cells (randomly set them to alive or dead)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            // Randomly set cells to alive (true) or dead (false)
            if (rand() % 2 == 0) {
                board[i][j].setAlive(true);  // Alive state
            }
            else {
                board[i][j].setAlive(false);  // Dead state
            }
        }
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