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
        Grid::loadGameFromCSV(ROWS, game_Board);
    }

    if (menu_option_1 == 2)
    {
        GameController* gc = new GameController();
    }


    return 0;
}


