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
    int countAliveNeighbours(int x, int y, int rows, int columns);
    bool areAllCellsDead(int rows, int columns);
};
