#include "User.h"

void User::showGames() {
	for (size_t i = 0; i < gamesAmount; i++)
	{
		games[i].ShowGame();

	}
}