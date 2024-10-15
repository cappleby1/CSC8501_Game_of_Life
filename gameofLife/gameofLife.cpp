#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

int STARTING_CELL_AMOUNT, GAME_TIME, ROWS, COLUMNS;

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
    game_board.randomiseAliveCells(STARTING_CELL_AMOUNT);
    cout << "\n" << "Initial Board: " << "\n";
    game_board.printGrid();

    game_board.saveGameToCSV();

    int menu_option_2;
    cout << "What question would you like to run?";

    switch(menu_option_2) 
    {
        case 1:
            for (int i = 0; i < GAME_TIME; ++i)
            {
                cout << "\n Turn " << (i + 1) << ":\n";
                game_board.updateGrid();
                game_board.printGrid();
            }
        break;
    }

}

int main()
{
    int menu_option_1;
    cout << "Main menu: " << "\n" << "1. Load file" << "\n" << "2. Start New";
    cin >> menu_option_1;

    if(menu_option_1 == 1)
    {
        // Load file
    }
    
    if(menu_option_1 == 2)
    {
        createNewGame();
    }

    return 0;
}


