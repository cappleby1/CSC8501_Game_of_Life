#include "Cell.h"
#include <iostream>

// Set state
void Cell::setAlive(bool state)
{
    is_alive = state;
}

// Check current state
bool Cell::isAliveState()
{
    return is_alive;
}

