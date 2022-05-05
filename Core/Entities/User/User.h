#include "../Game/Game.h"
struct User {
	//<-------constructor-------->
	User() {
		randNumber(arrNumbersGameNames, gamesAvailable, userGamesAmount);
		randNumber(arrNumbersUserNames, usersAmount, usersAmount);
		
		UserName = userNames[arrNumbersUserNames[index]];
		index++;
		password = 111;
		for (size_t i = 0; i < userGamesAmount; i++)
		{
			
			userGames[i].name = gamesAvailableArr[arrNumbersGameNames[i]];
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
	string password;
	//<-----------games---------->
	int userGamesAmount = rand() % ((gamesAvailable+1) -1)+1;
	Game* userGames = new Game[userGamesAmount];
	int* arrNumbersGameNames = new int[userGamesAmount];
	int* arrNumbersUserNames = new int[usersAmount];
	void randNumber(int*& arrNumbers, int gamesAvailable, int userGamesAmount);
	
	
};

void ShowGamesPopular(User a);
void ShowGamesRecomendations(User a);
void ShowGamesNew(User a);
void ShowGames(User a);
void ShowDownloads(User a);
bool ShowNotDownloads(User a);
void LibraryMenu(User a);
Game DownloadGame(Game*& userGames);
//void ShowNames(User*& arr, int usersAmount);