#include <iostream>

using namespace std;

void makeGrid(int GRID_SIZE, int STARTING_CELL_AMOUNT)
{
    int rows = GRID_SIZE;
    int columns = GRID_SIZE;

    // Create necessary memory
    char** array = new char* [rows]; 
    for (int i = 0; i < rows; ++i) {
        array[i] = new char[columns]; 
    }
    
    // Create the actual grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = ' '; 
        }
    }
    
    // Print the grid
    for (int i = 0; i < rows; ++i) {
        cout << ".";
        for (int j = 0; j < columns; ++j) {
            cout << array[i][j] << ".";
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


