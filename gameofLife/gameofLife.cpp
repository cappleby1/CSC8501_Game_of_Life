#include "main.h"

int STARTING_CELL_AMOUNT, GAME_TIME, ROWS, COLUMNS, CURRENT_TURN;



int main()
{
    int menu_option_1;
    cout << "Main menu: " << "\n" << "1. Load file" << "\n" << "2. Start New" << ":\n";
    cin >> menu_option_1;

    if (menu_option_1 == 1)
    {
        cout << "Enter amount of rows: " << "\n";
        cin >> ROWS;

        cout << "Enter amount of columns" << "\n";
        cin >> COLUMNS;

        cout << "Enter amount of turns:" << "\n";
        cin >> GAME_TIME;

        cout << "Creating grid" << "\n";

        Grid<Cell> game_board(ROWS, COLUMNS);
        game_board.printGrid();

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
        game_board.printGrid();
        question1(game_board, GAME_TIME);

        return 0;
    }

    if (menu_option_1 == 2)
    {
        createNewGame();
    }


    return 0;
}


