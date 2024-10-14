#include <iostream>
#include <fstream>

using namespace std;

int STARTING_CELL_AMOUNT, GAME_TIME, ROWS, COLUMNS;

class Cell {
    bool isAlive = false;

public:
    Cell(bool state = false) : isAlive(state) {}

    void setAlive(bool state)
    {
        isAlive = state;
    }

    bool isAliveState()
    {
        return isAlive;
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

        board = new Cell * [rows];
        for (int i = 0; i < rows; i++) 
        {
            board[i] = new Cell[columns]; 
        }
    }

    ~Grid()
    {
        // Deallocate memory for the board
        for (int i = 0; i < rows; i++) {
            delete[] board[i];
        }
        delete[] board;
    }

    void randomiseAliveCells()
    {
        srand(time(0)); // Use time to have a dynamic seed
        for (int n = 0; n < STARTING_CELL_AMOUNT; ++n) {
            int randomRow = rand() % rows;
            int randomCol = rand() % columns;

            // Ensure  don't overwrite an existing 'O'
            while (board[randomRow][randomCol].isAliveState()) {
                randomRow = rand() % rows;
                randomCol = rand() % columns;
            }

            board[randomRow][randomCol].setAlive(true);
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


