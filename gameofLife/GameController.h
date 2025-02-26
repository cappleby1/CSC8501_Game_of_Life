#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Grid.h"
using namespace std;

class GameController {
public:
	int CURRENT_TURN;
	int ROWS;
	int COLUMNS;
	int STARTING_CELL_AMOUNT;

	Grid* board;

	GameController(int rows = 10, int columns = 10, int starting_cell = 10, int current_turn = 0);

	void createNewGame(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT, int CURRENT_TURN);

	void menu();

	void saveController();

	void runForGameTime();
	void checkForShape();
};

#endif