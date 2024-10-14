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
};


void saveGame()
{
    cout << "Saving game";
    ofstream my_file("save_data.csv");

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cin >> CURRENT_GRID[i][j];
            my_file << "." << CURRENT_GRID[i][j] << ",";
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


