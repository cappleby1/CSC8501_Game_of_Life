#include "GameController.h"
#include <iostream>
#include <cstdlib>

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

    board = new Grid(ROWS, COLUMNS, STARTING_CELL_AMOUNT);
    board->randomiseAliveCells(STARTING_CELL_AMOUNT);
    cout << "\n" << "Initial Board: " << "\n";
    board->printGrid();

    board->saveGameToCSV();
    menu(GAME_TIME);
}

void GameController::menu(int GAME_TIME)
{
    int menu_option_2;
    cout << "What would you like to do? \n 1.Run for set amount of turns \n 2.Check for block \n 3.Check for beehive \n 4.Check for blink \n 5.Check for toad \n 6.Check for glider \n 7.Check for ship \n ";
    cin >> menu_option_2;

    switch (menu_option_2)
    {
        // Question 1
    case 1:
        question1(GAME_TIME);

        // Question 2
    case 2:
        question2();

        // Question 3
    case 3:
        question3();
        // Question 4
    case 4:
        question4();
    }
}

void GameController::question1(int GAME_TIME)
{
    for (int i = 0; i < GAME_TIME; ++i)
    {
        system("cls");
        cout << "\n Turn " << (i + 1) << ":\n";
        board->updateGrid();
        board->printGrid();

        if (board->areAllCellsDead())
        {
            cout << "\n" << "All cells dead";
            break;
        }

    }
	saveController();

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
            saveController();
        }

        CURRENT_TURN += 1;
        system("cls");
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        board->updateGrid();
        board->printGrid();

        if (board->checkForBlock())
        {
            system("cls");
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "2x2 found" << ":\n";
            board->printGrid();
            saveController();
        }

        if (board->checkForBeehive())
        {
            system("cls");
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "beehive found" << ":\n";
            board->printGrid();
            saveController();
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
            saveController();
        }

        CURRENT_TURN += 1;
        system("cls");
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        board->updateGrid();
        board->printGrid();

        if (board->checkForBlinker())
        {
            board->saveGameToCSV();
            system("cls");
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "blinker found" << ":\n";
            board->printGrid();
            saveController();
        }

        if (board->checkForToad())
        {
            board->saveGameToCSV();
            system("cls");
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "toad found" << ":\n";
            board->printGrid();
            saveController();
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
            saveController();
        }

        CURRENT_TURN += 1;
        system("cls");
        cout << "\n Turn " << CURRENT_TURN << ":\n";
        board->updateGrid();
        board->printGrid();

        if (board->checkForGlider())
        {
            board->saveGameToCSV();
            system("cls");
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "glider found" << ":\n";
            board->printGrid();
            saveController();
        }

        if (board->checkForShip())
        {
            board->saveGameToCSV();
            system("cls");
            cout << "\n Turn " << CURRENT_TURN << ":\n";
            cout << "\n" << "ship found" << ":\n";
            board->printGrid();
            saveController();
        }
    }
}

void GameController::saveController()
{
    int save_option;
    cout << "\n Save board & pause? 1. Yes 2. No" << "\n";
    cin >> save_option;
    if (save_option == 1)
    {
        board->saveGameToCSV();
        cout << "Game saved. Press any key to continue..." << endl;
    }
}


GameController::GameController(int rows, int columns, int starting_cell, int game_time, int current_turn)
{
    createNewGame(rows, columns, starting_cell, game_time, current_turn);
}
