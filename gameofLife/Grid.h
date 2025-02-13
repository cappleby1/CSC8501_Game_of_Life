#include "Cell.h"
using namespace std;

class Grid {
public:
    Cell** board;
    int rows;
    int columns;
    int CURRENT_TURN;

    Grid(int ROWS, int COLUMNS);
    void randomiseAliveCells(int STARTING_CELL_AMOUNT);
    void printGrid();
    void updateGrid();
    int countAliveNeighbours(int x, int y, int rows, int columns);
    bool areAllCellsDead(int rows, int columns);

    bool checkForBlock(int rows, int columns, Grid board);
    bool checkForBeehive(int rows, int columns, Grid board);
    bool checkForBlinker(int rows, int columns, Grid board);
    bool checkForToad(int rows, int columns, Grid board);
    bool checkForGlider(int rows, int columns, Grid board);
    bool checkForShip(int rows, int columns, Grid board);

    void saveGameToCSV(int rows, int columns);
};
