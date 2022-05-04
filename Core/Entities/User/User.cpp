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

