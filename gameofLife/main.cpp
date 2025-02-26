#include <iostream> 
#include "GameController.h"
#include "Grid.h"

int main()
{
    int menu_option_1;
    cout << "Main menu: " << "\n" << "1. Load file" << "\n" << "2. Start New" << ":\n";
    cin >> menu_option_1;

    if (menu_option_1 == 1)
    {
        Grid game_board;
        int ROWS = 10;
        game_board.loadGameFromCSV(ROWS, game_board);
    }

    if (menu_option_1 == 2)
    {
        GameController* gc = new GameController();
    }


    return 0;
}


