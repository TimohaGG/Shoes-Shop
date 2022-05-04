#include "../Game/Game.h"
struct User {
	//<-------constructor-------->
	User() {
		randNumber(arrNumbers, gamesAvailable, userGamesAmount);
		
		for (size_t i = 0; i < userGamesAmount; i++)
		{
			userGames[i].name = gamesAvailableArr[arrNumbers[i]];
			userGames[i].hoursPlayed = rand() % 2000;
			userGames[i].raiting = rand() % 10;
			userGames[i].memoryNeeded = rand() % (120 - 10) + 10;
			userGames[i].newGame = rand() % 2;
			userGames[i].achivements = rand() % 100;
			userGames[i].instaled = rand() % 2;
			userGames[i].downloads = rand() % (1000000-90000)+70000;
		}
	}
	//<-------fields-------->
	string UserName;
	//<-----------games---------->
	int userGamesAmount = rand() % ((gamesAvailable+1) -1)+1;
	Game* userGames = new Game[userGamesAmount];
	int* arrNumbers = new int[userGamesAmount];

	void randNumber(int*& arrNumbers, int gamesAvailable, int userGamesAmount);
	void ShowGames();
	
};

void ShowGamesPopular(User a);
void ShowGamesRecomendations(User a);
void ShowGamesNew(User a);