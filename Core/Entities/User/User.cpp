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
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].downloads>70000) {
			a.userGames[i].ShowGame();
		}
	}
}

void ShowGamesRecomendations(User a) {
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].raiting > 8) {
			a.userGames[i].ShowGame();
		}
	}
}

void ShowGamesNew(User a) {
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		if (a.userGames[i].newGame) {
			a.userGames[i].ShowGame();
		}
	}
}

