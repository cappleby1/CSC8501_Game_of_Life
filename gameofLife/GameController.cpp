#include "GameController.h"
#include <iostream>

using namespace std;

void GameController::createNewGame(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT, int GAME_TIME, int CURRENT_TURN)
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

    game_board.saveGameToCSV(ROWS, COLUMNS);

    int menu_option_2;
    cout << "What question would you like to run?" << ":\n";
    cin >> menu_option_2;

    switch (menu_option_2)
    {
        // Question 1
    case 1:
        question1(game_board, GAME_TIME);
        break;

        // Question 2
    case 2:
        question2(game_board, CURRENT_TURN);
        break;

        // Question 3
    case 3:
        question3(game_board, CURRENT_TURN);
        break;
        // Question 4
    case 4:
        question4(game_board, CURRENT_TURN);
        break;
    case 5:
        // Question 5
        question5(ROWS, COLUMNS, STARTING_CELL_AMOUNT);
        break;
    }
}

void GameController::question1(Grid game_board, int GAME_TIME)
{
    for (int i = 0; i < GAME_TIME; ++i)
    {
        cout << "\n Turn " << (i + 1) << ":\n";
        game_board.updateGrid();
        game_board.printGrid();

        int save_option;
        cout << "Save board & pause? 1. Yes 2. No" << "\n";
        cin >> save_option;
        if (save_option == 1)
        {
            game_board.saveGameToCSV();
            break;
        }
        else
        {
            continue;
        }
    }

}

void GameController::question2(Grid game_board, int CURRENT_TURN)
{
    bool found = false;
    CURRENT_TURN = 0;
    while (!found)
    {

        if (game_board.areAllCellsDead())
        {
            cout << "\n" << "All cells dead";
            break;
        }

        CURRENT_TURN += 1;
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        game_board.updateGrid();
        game_board.printGrid();

        if (game_board.checkForBlock())
        {
            game_board.saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "2x2 found" << ":\n";
            game_board.printGrid();
            break;
        }

        if (game_board.checkForBeehive())
        {
            game_board.saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "beehive found" << ":\n";
            game_board.printGrid();
            break;
        }
    }
}

void GameController::question3(Grid game_board, int CURRENT_TURN)
{
    bool found = false;
    CURRENT_TURN = 0;
    while (!found)
    {

        if (game_board.areAllCellsDead())
        {
            cout << "\n" << "All cells dead";
            break;
        }

        CURRENT_TURN += 1;
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        game_board.updateGrid();
        game_board.printGrid();

        if (game_board.checkForBlinker())
        {
            game_board.saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "blinker found" << ":\n";
            game_board.printGrid();
            break;
        }

        if (game_board.checkForToad())
        {
            game_board.saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "toad found" << ":\n";
            game_board.printGrid();
            break;
        }
    }
}

void GameController::question4(Grid game_board, int CURRENT_TURN)
{
    bool found = false;
    CURRENT_TURN = 0;
    while (!found)
    {

        if (game_board.areAllCellsDead())
        {
            cout << "\n" << "All cells dead";
            break;
        }

        CURRENT_TURN += 1;
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        game_board.updateGrid();
        game_board.printGrid();

        if (game_board.checkForGlider())
        {
            game_board.saveGameToCSV(ROWS,COLUMNS);
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "glider found" << ":\n";
            game_board.printGrid();
            break;
        }

        if (game_board.checkForShip())
        {
            game_board.saveGameToCSV(ROWS, COLUMNS);
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "ship found" << ":\n";
            game_board.printGrid();
            break;
        }
    }
}

int GameController::calculateERN(const Pattern& pattern, int STARTING_CELL_AMOUNNT, int ROWS, int COLUMNS) {

    // min required needed capped by starting population & also for grid size
    int needed_alive_cells = min(pattern.aliveCells, STARTING_CELL_AMOUNNT);
    int needed_row_amount = min(pattern.width, ROWS);
    int needed_column_amount = min(pattern.height, COLUMNS);

    // returns width + height + amount of alive cells (to be repeated per pattern)
    return needed_row_amount + needed_column_amount + needed_alive_cells;
}

void GameController::question5(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT)
{

    Pattern patterns[] =
    {
    {"Block", 2, 2, 4},
    {"Beehive", 3, 4, 6},
    {"Blinker", 1, 3, 3},
    {"Toad", 2, 4, 6},
    {"Spaceship", 3, 5, 5},
    {"Glider", 3, 3, 5},
    {"Lightweight Spaceship (LWSS)", 3, 5, 5}
    };

    cout << "ERN Based on grid & starting number: " << "\n";
    for (int i = 0; i < 7; ++i) {
        int ern = calculateERN(patterns[i], ROWS, COLUMNS, STARTING_CELL_AMOUNT);
        cout << patterns[i].name << ": " << ern << "\n";
    }
}

GameController::GameController(int rows, int columns, int starting_cell, int game_time, int current_turn)
{
    createNewGame(rows, columns, starting_cell, game_time, current_turn);
}
