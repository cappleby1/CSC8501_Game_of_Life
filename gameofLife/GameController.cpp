#include "GameController.h"
#include "Grid.h"
#include <iostream>

using namespace std;

void GameController::createNewGame(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT, int GAME_TIME)
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