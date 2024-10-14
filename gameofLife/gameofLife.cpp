#include <iostream>
#include <fstream>

using namespace std;

int STARTING_CELL_AMOUNT, GAME_TIME, ROWS, COLUMNS;

class Cell {
    bool is_alive = false;

public:
    Cell(bool state = false) : is_alive(state) {}

    // Set state
    void setAlive(bool state)
    {
        is_alive = state;
    }
    
    // Check current state
    bool isAliveState()
    {
        return is_alive;
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

    void randomiseAliveCells()
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

    void printGrid()
    {
        cout << "\n" << "Game Baord: " << "\n";
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
};


int main()
{
    cout << "Enter amount of rows: " << "\n";
    cin >> ROWS;
    
    cout << "Enter amount of columns: " << "\n";
    cin >> COLUMNS;

    cout << "Enter amount of starting cells: " << "\n";
    cin >> STARTING_CELL_AMOUNT;

    cout << "Enter amount of turns: " << "\n";
    cin >> GAME_TIME;

    Grid game_board(ROWS, COLUMNS);
    game_board.randomiseAliveCells();
    game_board.printGrid();
    

    return 0;
}


