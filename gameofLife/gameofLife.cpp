#include <iostream>

using namespace std;

void makeGrid(int GRID_SIZE, int STARTING_CELL_AMOUNT)
{
    // Create necessary memory
    char** array = new char* [GRID_SIZE]; 
    for (int i = 0; i < GRID_SIZE; ++i) {
        array[i] = new char[GRID_SIZE]; 
    }
    
    // Create the actual grid
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            array[i][j] = '.'; 
        }
    }
    
    // Print the grid
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl; 
    }
}

int main()
{
    int GRID_SIZE, STARTING_CELL_AMOUNT, GAME_TIME;

    cout << "Enter grid size: " << "\n";
    cin >> GRID_SIZE;

    cout << "Enter amount of starting cells: " << "\n";
    cin >> STARTING_CELL_AMOUNT;

    cout << "Enter amount of turns: ";
    cin >> GAME_TIME;

    makeGrid(GRID_SIZE, STARTING_CELL_AMOUNT);

}


