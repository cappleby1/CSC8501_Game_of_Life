#include "main.h"

void question3(Grid<Cell> game_board, int CURRENT_TURN)
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