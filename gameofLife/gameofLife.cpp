#include <iostream>
#include <fstream>

using namespace std;

int GRID_SIZE, STARTING_CELL_AMOUNT, GAME_TIME, ROWS, COLUMNS;

class Cell
{
    bool isAlive;

public:
    Cell()
    {
        isAlive = false;
    }
};

class Grid
{
    Cell** board;
    int rows;
    int columns;

public:
    Grid(int ROWS, int COLUMNS)
    {
        rows = ROWS;
        columns = COLUMNS;

        board = new Cell* [rows];
        for (int i = 0; i < rows; i++)
        {
            board = new Cell* [columns];
        }
    }

    // Change some random position to "O"
    srand(time(0)); // Use time to have a dynamic seed
    for (int n = 0; n < STARTING_CELL_AMOUNT; ++n) {
        int randomRow = rand() % rows;
        int randomCol = rand() % columns;

        // Ensure  don't overwrite an existing 'O'
        while (array[randomRow][randomCol] == 'O') {
            randomRow = rand() % rows;
            randomCol = rand() % columns;
        }

        array[randomRow][randomCol] = 'O'; 
    }
    
    // Print the grid
    for (int i = 0; i < rows; ++i) {
        cout << "."; // Used to make the begining corner
        for (int j = 0; j < columns; ++j) {
            cout << array[i][j] << ".";
        }
    }
    my_file.close();
    cout << "File saved";
}


int main()
{
    cout << "Enter amount of rows: " << "\n";
    cin >> ROWS;
    
    cout << "Enter amount of height: " << "\n";
    cin >> COLUMNS;

    cout << "Enter amount of starting cells: " << "\n";
    cin >> STARTING_CELL_AMOUNT;

    cout << "Enter amount of turns: " << "\n";
    cin >> GAME_TIME;

    Grid game_board(ROWS, COLUMNS);
    

    return 0;
}


