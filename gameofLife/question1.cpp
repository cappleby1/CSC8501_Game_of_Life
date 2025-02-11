#include "main.h"
using namespace std;

void question1(Grid<Cell> game_board, int GAME_TIME)
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
