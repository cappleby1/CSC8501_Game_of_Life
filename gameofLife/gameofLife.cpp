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
    void updateGrid() {

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
                if (board[i][j].isAliveState()) {
                    // Cell will be alive for next gen if it has 2 or 3 alive neighbours
                    newBoard[i][j].setAlive(aliveNeighbors == 2 || aliveNeighbors == 3);
                }
                else {
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

private:
    int countAliveNeighbors(int x, int y) {
        int count = 0;
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
    cout << "\n" << "Initial Board: " << "\n";
    game_board.printGrid();

    for (int i = 0; i < GAME_TIME; ++i) {
        cout << "\n Turn " << (i + 1) << ":\n";
        game_board.updateGrid();
        game_board.printGrid();
    }
    

    return 0;
}


