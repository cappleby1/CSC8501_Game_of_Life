#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "Cell.h"

class Grid {
public:
    Cell** board;
    int rows;
    int columns;

    Grid(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT);
    Grid();
    ~Grid();

    void randomiseAliveCells(int STARTING_CELL_AMOUNT);
    void printGrid();
    void updateGrid();
    int countAliveNeighbours(int i, int j);
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

#endif