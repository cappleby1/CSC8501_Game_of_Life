using namespace std;
#include "Grid.h"

class GameController {
	void createNewGame(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT, int GAME_TIME, int CURRENT_TURN);
	int calculateERN(const Pattern& pattern, int STARTING_CELL_AMOUNNT, int ROWS, int COLUMNS);

	void question1(Grid game_board, int GAME_TIME);
	void question2(Grid game_board, int GAME_TIME);
	void question3(Grid game_board, int GAME_TIME);
	void question4(Grid game_board, int GAME_TIME);
	void question5(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT);
};