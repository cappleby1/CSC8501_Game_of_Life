#include "Cell.h"

using namespace std;

class Grid {
public:
    Grid** board;
    int rows;
    int columns;

    Grid(int ROWS, int COLUMNS);
    void randomiseAliveCells(int STARTING_CELL_AMOUNT);
    void printGrid();
    void updateGrid();
};
