#include <iostream>
#include <fstream>

using namespace std;

int STARTING_CELL_AMOUNT, GAME_TIME, ROWS, COLUMNS, CURRENT_TURN;

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

    // Overrides operator to allow the state of the cell to be written in the CSV (converting it to 0/1)
    friend ostream& operator<<(ostream& os, Cell& cell) 
    {
        os << cell.is_alive;
        return os;
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

    void saveGameToCSV()
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

    bool checkForBlock()
    {
        // Check for each possible 2x2 grid
        for (int i = 0; i < rows -1; ++i) 
        {
            for (int j = 0; j < columns -1; ++j) 
            {
                bool cell1 = board[i][j].isAliveState();
                bool cell2 = board[i][j + 1].isAliveState();
                bool cell3 = board[i + 1][j].isAliveState();
                bool cell4 = board[i + 1][j + 1].isAliveState();

                bool top_dead = (i == 0) || !board[i - 1][j].isAliveState() && !board[i - 1][j + 1].isAliveState();
                bool left_dead = (j == 0) || !board[i][j - 1].isAliveState();
                bool right_dead = (j + 1 == columns - 1) || !board[i][j + 2].isAliveState();
                bool bottom_dead = (i + 1 == rows - 1) || !board[i + 2][j].isAliveState() && !board[i + 2][j + 1].isAliveState();


                // Check the 2x2 grid
                if (cell1 && cell2 && cell3 && cell4 && top_dead && left_dead && right_dead && bottom_dead)
                {
                    // Found a matching 2x2 grid
                    return true;
                }
            }
        }
        return false;
    }

    bool checkForBeehive()
    {
        for (int i = 0; i < rows - 3; ++i)
        {
            for (int j = 0; j < columns - 2; ++j)
            {
                bool cell1 = board[i][j].isAliveState();
                bool cell2 = board[i + 1][j].isAliveState();
                bool cell3 = board[i + 2][j].isAliveState();
                bool cell4 = board[i + 3][j + 1].isAliveState();
                bool cell5 = board[i + 1][j + 2].isAliveState();
                bool cell6 = board[i + 2][j + 2].isAliveState();
                bool cell7 = board[i][j + 1].isAliveState();


                if (!cell1 && cell2 && cell3 && cell4 && cell5 && cell6 && cell7)
                {
                    // Found a beehive
                    return true; 
                }
            }
        }
        return false;

    }

    bool areAllCellsDead()
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

private:
    int countAliveNeighbors(int x, int y) {
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
};


void createNewGame()
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

    game_board.saveGameToCSV();

    int menu_option_2;
    cout << "What question would you like to run?" << ":\n";
    cin >> menu_option_2;

    switch (menu_option_2)
    {
    // Question 1
    case 1:
        for (int i = 0; i < GAME_TIME; ++i)
        {
            cout << "\n Turn " << (i + 1) << ":\n";
            game_board.updateGrid();
            game_board.printGrid();
        }
        break;

    // Question 2
    case 2:
        bool found = false;
        CURRENT_TURN = 0;
        while(!found)
        {

            if (game_board.areAllCellsDead())
            {
                cout << "\n" << "All cells dead";
                break;
            }

            CURRENT_TURN += 1;
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            game_board.updateGrid();

            if (game_board.checkForBlock())
            {
                cout << "\n Turn " << CURRENT_TURN << ":\n";
                cout << "\n" << "2x2 found" << ":\n";
                game_board.printGrid();
                break;
            }
            
            if (game_board.checkForBeehive())
            {
                cout << "\n Turn " << CURRENT_TURN << ":\n";
                cout << "\n" << "beehive found" << ":\n";
                game_board.printGrid();
                break;
            }
            
        }
        break;
    }

}

int main()
{
    int menu_option_1;
    cout << "Main menu: " << "\n" << "1. Load file" << "\n" << "2. Start New" << ":\n";
    cin >> menu_option_1;

    if (menu_option_1 == 1)
    {
        // Load file
    }

    if (menu_option_1 == 2)
    {
        createNewGame();
    }


    return 0;
}


