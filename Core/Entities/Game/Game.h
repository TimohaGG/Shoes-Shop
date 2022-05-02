#pragma once
#include "../../Lib/Lib.h"

struct Game {
	string name;
	uint32_t raiting;
	double hoursPlayed;
	uint32_t achivements;
	uint32_t memoryNeeded;
	bool newGame;

};
extern string GameNames[10];
extern int* arrNumbers;
void randNumber(int*& arr);
Game fillGames(Game*& games);
void showGames(Game* games);
