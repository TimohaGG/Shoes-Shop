#include "../Game/Game.h"
struct User {
	
	//<-------fields-------->
	string UserName;
	string password;
	//<-----------games---------->
	int userGamesAmount = rand() % ((gamesAvailable+1) -1)+1;
	Game* userGames = new Game[userGamesAmount];
	int* arrNumbersGameNames = new int[userGamesAmount];
	//<-----------methods---------->
	void randNumber(int*& arrNumbers, int gamesAvailable, int userGamesAmount);
	void fillUser(string* gamesAvailableArr);
	
};

void ShowGamesPopular(User a);
void ShowGamesRecomendations(User a);
void ShowGamesNew(User a);
void ShowGames(User a);
void ShowDownloads(User a);
bool ShowNotDownloads(User a);
void LibraryMenu(User a);
Game DownloadGame(Game*& userGames);
int Login(User* a, int usersAmount);
void randNumberUsernames(int*& arrNumbers, int usernamesAvailable);
User* FillUsernames(User*& users, string* usernames, int* arrNumbers, int usersAmount);
int Registration(User*& users, int& usersAmount);
void ShowProfile(User a);
void ShowFriends(User a);
//void ShowNames(User*& arr, int usersAmount);