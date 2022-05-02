#include "Core/Entities/Game/Game.h"

int main() {
	srand(time(NULL));
	setlocale(0,"");
	Game* games = new Game[GamesAvailable];
	fillGames(games);
	showGames(games);
}
