#include "Grid.h"
using namespace std;

class GameController {
public:
	int CURRENT_TURN;
	int ROWS;
	int COLUMNS;
	int GAME_TIME;
	int STARTING_CELL_AMOUNT;

	GameController(int rows = 10, int columns = 10, int starting_cell = 10, int game_time = 0, int current_turn = 0);

	void createNewGame(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT, int GAME_TIME, int CURRENT_TURN);
	int calculateERN(const Pattern& pattern, int STARTING_CELL_AMOUNNT, int ROWS, int COLUMNS);

	void question1(Grid game_board, int GAME_TIME);
	void question2(Grid game_board, int GAME_TIME);
	void question3(Grid game_board, int GAME_TIME);
	void question4(Grid game_board, int GAME_TIME);
	void question5(int ROWS, int COLUMNS, int STARTING_CELL_AMOUNT);
};