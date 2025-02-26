#include "GameController.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

void GameController::createNewGame(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT, int CURRENT_TURN)
{
    cout << "Enter amount of rows: " << "\n";
    cin >> ROWS;

    cout << "Enter amount of columns: " << "\n";
    cin >> COLUMNS;

    cout << "Enter amount of starting cells: " << "\n";
    cin >> STARTING_CELL_AMOUNT;

    board = new Grid(ROWS, COLUMNS, STARTING_CELL_AMOUNT);
    board->randomiseAliveCells(STARTING_CELL_AMOUNT);
    cout << "\n" << "Initial Board: " << "\n";
    board->printGrid();

    board->saveGameToCSV();
    menu();
}

void GameController::menu()
{
    int menu_option_2;
    cout << "What would you like to do? \n 1.Run for set amount of turns \n 2.Check for shape ";
    cin >> menu_option_2;

    switch (menu_option_2)
    {
    case 1:
        runForGameTime();
    case 2:
        checkForShape();

    }
}

void GameController::runForGameTime()
{
    int game_time;
    cout << "\n Enter amount of turns: \n";
    cin >> game_time;

    for (int i = 0; i < game_time; ++i)
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

void GameController::checkForShape()
{
    bool found = false;
    CURRENT_TURN = 0;

    string selectedShape;
    std::cout << "Enter the shape you want to find (block, beehive, glider, etc.): ";
    std::cin >> selectedShape;

    transform(selectedShape.begin(), selectedShape.end(), selectedShape.begin(), ::tolower);

    while (!found)
    {
        if (board->areAllCellsDead())
        {
            std::cout << "\n" << "All cells dead";
            saveController();
            break;  
        }

        CURRENT_TURN += 1;
        system("cls");  
        std::cout << "\n Turn " << CURRENT_TURN << ":\n";
        board->updateGrid();
        board->printGrid();

        if (selectedShape == "block" && board->checkForBlock())
        {
            system("cls");
            std::cout << "\n Turn " << CURRENT_TURN << ":\n";
            std::cout << "\n" << "2x2 Block found" << ":\n";
            board->printGrid();
            saveController();
            found = true;  
        }
        else if (selectedShape == "beehive" && board->checkForBeehive())
        {
            system("cls");
            std::cout << "\n Turn " << CURRENT_TURN << ":\n";
            std::cout << "\n" << "Beehive found" << ":\n";
            board->printGrid();
            saveController();
            found = true;  
        }
        
        else if (selectedShape == "glider" && board->checkForGlider())  
        {
            system("cls");
            std::cout << "\n Turn " << CURRENT_TURN << ":\n";
            std::cout << "\n" << "Glider found" << ":\n";
            board->printGrid();
            saveController();
            found = true; 
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


GameController::GameController(int rows, int columns, int starting_cell, int current_turn)
{
    createNewGame(rows, columns, starting_cell, current_turn);
}
