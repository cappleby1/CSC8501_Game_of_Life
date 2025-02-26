#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Grid.h"
using namespace std;

class GameController {
public:
	int CURRENT_TURN;
	int ROWS;
	int COLUMNS;
	int GAME_TIME;
	int STARTING_CELL_AMOUNT;
	Grid* board;

	GameController(int rows = 10, int columns = 10, int starting_cell = 10, int game_time = 0, int current_turn = 0);

	void createNewGame(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT, int GAME_TIME, int CURRENT_TURN);

	void question1(int GAME_TIME);
	void question2();
	void question3();
	void question4();
};

#endif