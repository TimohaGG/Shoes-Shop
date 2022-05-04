#include"User.h"

bool noRepeat(int*& arr, int number) {
	for (size_t i = 0; i < gamesAvailable; i++)
	{
		if (arr[i] == number)
			return false;
	}
	return true;
}


void User::randNumber(int*& arrNumbers, int gamesAvailable, int userGamesAmount) {
	arrNumbers[0] = rand() % gamesAvailable;
	for (size_t i = 1; i < userGamesAmount; i++)
	{
		int number;
		do {
			number = rand() % gamesAvailable;
			//cout << number << endl;
		} while (!noRepeat(arrNumbers, number));
		arrNumbers[i] = number;

	}
}

void User::ShowGames() {
	for (size_t i = 0; i < userGamesAmount; i++)
	{
		userGames[i].ShowGame();
	}
}



void ShowGamesPopular(User a) {
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

void ShowGamesRecomendations(User a) {
	bool available = false;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].raiting >5) {
			a.userGames[i].ShowGame();
			available = true;
		}
	}
	if (!available) {
		cout << "Здесь ничего(" << endl;
	}
}

void ShowGamesNew(User a) {
	bool available=false;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].newGame) {
			a.userGames[i].ShowGame();
			available = true;
		}
	}
	if (!available) {
		cout << "Здесь ничего("<<endl;
	}
}

