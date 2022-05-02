#pragma once
#include "../Game/Game.h"

struct User {
	//<-------constructor-------->
	User() {
		fillGames(games, gamesAmount);
	}
	//<-------fields-------->
	string UserName;
	//<-----------games---------->
	int gamesAmount=rand()% GamesAvailable;
	Game* games = new Game[gamesAmount];

	//<-------methods-------->
	void showGames();
	
};
