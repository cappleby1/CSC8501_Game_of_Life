#include "main.h"

struct Pattern {
    const char* name;
    int width;
    int height;
    int aliveCells;
};


int calculateERN(const Pattern& pattern, int STARTING_CELL_AMOUNNT, int ROWS, int COLUMNS) {

    // min required needed capped by starting population & also for grid size
    int needed_alive_cells = min(pattern.aliveCells, STARTING_CELL_AMOUNNT);
    int needed_row_amount = min(pattern.width, ROWS);
    int needed_column_amount = min(pattern.height, COLUMNS);

    // returns width + height + amount of alive cells (to be repeated per pattern)
    return needed_row_amount + needed_column_amount + needed_alive_cells;
}

void question5(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT)
{

    Pattern patterns[] = 
    {
    {"Block", 2, 2, 4},
    {"Beehive", 3, 4, 6},
    {"Blinker", 1, 3, 3},
    {"Toad", 2, 4, 6},
    {"Spaceship", 3, 5, 5},
    {"Glider", 3, 3, 5},
    {"Lightweight Spaceship (LWSS)", 3, 5, 5}
    };
    
    cout << "ERN Based on grid & starting number: " << "\n";
    for (int i = 0; i < 7; ++i) {
        int ern = calculateERN(patterns[i], ROWS, COLUMNS, STARTING_CELL_AMOUNT);
        cout << patterns[i].name << ": " << ern << "\n";
    }
}