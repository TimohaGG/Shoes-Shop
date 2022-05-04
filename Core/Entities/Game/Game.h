#include "../../Lib/Lib.h"

struct Game {

	//<--------fields-------->
	string name;
	double hoursPlayed;
	uint32_t raiting;
	uint32_t achivements;
	uint32_t memoryNeeded;
	uint32_t downloads;
	bool newGame;
	bool instaled;

	//<--------methods-------->
	void ShowGame();
};
int GetMaxGames();
int GetUsersAmount();
string* GetGamesNames(string*& arr);
string* GetUsersNames(string*& arr);

