#include "Cell.h"
using namespace std;

class Grid {
public:
    Cell** board;
    int rows;
    int columns;

    Grid(int ROWS, int COLUMNS);

    void randomiseAliveCells(int STARTING_CELL_AMOUNT);
    void printGrid();
    void updateGrid();
    int countAliveNeighbours();
    bool areAllCellsDead();

    bool checkForBlock();
    bool checkForBeehive();
    bool checkForBlinker();
    bool checkForToad();
    bool checkForGlider();
    bool checkForShip();

    void saveGameToCSV();
    void loadGameFromCSV(int ROWS, Grid game_board);
};
