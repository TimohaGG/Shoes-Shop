#include"User.h"

bool noRepeat(int*& arr, int number, int gamesAvailable) {
	for (size_t i = 0; i < gamesAvailable; i++)
	{
		if (arr[i] == number)
			return false;
	}
	return true;
}


void User::randNumber(int*& arrNumbers, int gamesAvailable, int userGamesAmount) {
	//int buf = gamesAvailable;
	arrNumbers[0] = rand() % gamesAvailable;
	for (size_t i = 1; i < userGamesAmount; i++)
	{
		int number;
		do {
			number = rand() % gamesAvailable;
			//cout << number << endl;
		} while (!noRepeat(arrNumbers, number, gamesAvailable));
		arrNumbers[i] = number;

	}
}

void ShowGames(User a) {
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		a.userGames[i].ShowGame();
	}
}



void ShowGamesPopular(User a)
{
	bool available = false;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].downloads>70000) {
			a.userGames[i].ShowGame();
			available = true;
		}
	}
	if (!available) {
		cout << "Здесь ничего(" << endl;
	}
}


void ShowGamesRecomendations(User a)
{
	bool available = false;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].raiting > 5) {
			a.userGames[i].ShowGame();
			available = true;
		}
	}
	if (!available) {
		cout << "Здесь ничего(" << endl;
	}
}
void ShowGamesNew(User a) {
	bool available = false;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].newGame) {
			a.userGames[i].ShowGame();
			available = true;
		}
	}
	if (!available) {
		cout << "Здесь ничего(" << endl;
	}
}



void ShowDownloads(User a) {
	bool available = false;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].instaled) {
			a.userGames[i].ShowGame();
			available = true;
		}
	}
	if (!available) {
		cout << "Здесь ничего(" << endl;
	}
}

bool ShowNotDownloads(User a)
{
	bool available = false;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (!a.userGames[i].instaled) {
			a.userGames[i].ShowGame();
			available = true;
		}
	}
	if (!available) {
		cout << "Здесь ничего(" << endl;
		return false;
	}
	return true;
}

Game DownloadGame(User& a) {
	while (true) {
		cout << "Какую игру установить?"<<endl<<endl;
		string choise;
		if (ShowNotDownloads(a)) {
			cin.ignore();
			getline(cin, choise);
			for (size_t i = 0; i < a.userGamesAmount; i++)
			{
				if (choise == a.userGames[i].name) {
					a.userGames[i].instaled = true;
					return*a.userGames;
				}
			}
			cout << "Такой игры нету" << endl;
			PAUSE;
			CLEAR;
		}
		else {
			break;
		}
	}
}

void LibraryMenu(User a)
{
	while (true) {
		cout << "1. Показать загрузки" << endl <<
			"2. Загрузить игру" << endl <<
			"0. Выход" << endl;
		int choise;
		cin >> choise;
		if(choise == 1) {
			ShowDownloads(a);
		}
		else if (choise == 2) {
			DownloadGame(a);
		}
		else {
			break;
		}
		PAUSE;
		CLEAR;
	}
	CLEAR;
	
}
//
//void ShowNames(User*& arr, int usersAmount) {
//	for (size_t i = 0; i < usersAmount; i++)
//	{
//		cout << arr[i].UserName << endl;
//	}
//}