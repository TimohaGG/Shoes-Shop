#pragma once
#include "../../Lib/Lib.h"

struct Game {
	 string GameNames[GamesAvailable];
	 int* arrNumbers;
	 int index = 0;
	
	//<--------fields-------->
	string name;
	double hoursPlayed;
	uint32_t raiting;
	uint32_t achivements;
	uint32_t memoryNeeded;
	bool newGame;
	bool instaled;

	//<--------methods-------->
	void ShowGame();
};


void randNumber(int*& arr);
Game fillGames(Game*& games, int userGames);

