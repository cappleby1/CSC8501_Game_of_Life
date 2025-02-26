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

    board = new Grid(ROWS, COLUMNS);
    board->randomiseAliveCells(STARTING_CELL_AMOUNT);
    cout << "\n" << "Initial Board: " << "\n";
    board->printGrid();

    board->saveGameToCSV();

    int menu_option_2;
    cout << "What question would you like to run?" << ":\n";
    cin >> menu_option_2;

    switch (menu_option_2)
    {
        // Question 1
    case 1:
        question1();
        break;

        // Question 2
    case 2:
        question2();
        break;

        // Question 3
    case 3:
        question3();
        break;
        // Question 4
    case 4:
        question4();
        break;
    }
}

void GameController::question1()
{
    for (int i = 0; i < GAME_TIME; ++i)
    {
        cout << "\n Turn " << (i + 1) << ":\n";
        board->updateGrid();
        board->printGrid();

        int save_option;
        cout << "Save board & pause? 1. Yes 2. No" << "\n";
        cin >> save_option;
        if (save_option == 1)
        {
            board->saveGameToCSV();
            break;
        }
        else
        {
            continue;
        }
    }

}

void GameController::question2()
{
    bool found = false;
    CURRENT_TURN = 0;
    while (!found)
    {

        if (board->areAllCellsDead())
        {
            cout << "\n" << "All cells dead";
            break;
        }

        CURRENT_TURN += 1;
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        board->updateGrid();
        board->printGrid();

        if (board->checkForBlock())
        {
            board->saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "2x2 found" << ":\n";
            board->printGrid();
            break;
        }

        if (board->checkForBeehive())
        {
            board->saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "beehive found" << ":\n";
            board->printGrid();
            break;
        }
    }
}

void GameController::question3()
{
    bool found = false;
    CURRENT_TURN = 0;
    while (!found)
    {

        if (board->areAllCellsDead())
        {
            cout << "\n" << "All cells dead";
            break;
        }

        CURRENT_TURN += 1;
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        board->updateGrid();
        board->printGrid();

        if (board->checkForBlinker())
        {
            board->saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "blinker found" << ":\n";
            board->printGrid();
            break;
        }

        if (board->checkForToad())
        {
            board->saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "toad found" << ":\n";
            board->printGrid();
            break;
        }
    }
}

void GameController::question4()
{
    bool found = false;
    CURRENT_TURN = 0;
    while (!found)
    {

        if (board->areAllCellsDead())
        {
            cout << "\n" << "All cells dead";
            break;
        }

        CURRENT_TURN += 1;
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        board->updateGrid();
        board->printGrid();

        if (board->checkForGlider())
        {
            board->saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "glider found" << ":\n";
            board->printGrid();
            break;
        }

        if (board->checkForShip())
        {
            board->saveGameToCSV();
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "ship found" << ":\n";
            board->printGrid();
            break;
        }
    }
}


GameController::GameController(int rows, int columns, int starting_cell, int game_time, int current_turn)
{
    createNewGame(rows, columns, starting_cell, game_time, current_turn);
}
