#include <iostream>

using namespace std;

class Cell {

public:
    bool is_alive = false;
    Cell(bool state = false) : is_alive(state) {}

    void setAlive(bool state);
    bool isAliveState();



    // Overrides operator to allow the state of the cell to be written in the CSV (converting it to 0/1)
    friend ostream& operator<<(ostream& os, Cell& cell)
    {
        os << cell.is_alive;
        return os;
    }

    // Ovverides to allow the CSV to be loaded back to an array
    friend istream& operator>>(istream& is, Cell& cell) {
        int state;
        is >> state;
        cell.is_alive = (state != 0);
        return is;
    }

};

struct Pattern {
    const char* name;
    int width;
    int height;
    int aliveCells;
};
