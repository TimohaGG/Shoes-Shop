#include"Game.h"

extern string GameNames[GamesAvailable]{"Counter Strike: Global Offensive","Just Cause 3","GTA5","Far Cry 5","Little Nightmares","Geometry Dash","Raft","Pubg","Tomb Raider","Crossout","Dishonered", "Far Cry 4","Kingdom Come Delivery","Red Dead Redemption 2","Sims 4","Fallout 4","Fallout 76","Far Cry New Dawn","Far Cry Primal","Far Cry 3"};
extern int* arrNumbers=new int[GamesAvailable];

bool noRepeat(int arr[GamesAvailable], int number) {
	for (size_t i = 0; i < GamesAvailable; i++)
	{
		if (arr[i] == number)
			return false;
	}
	return true;
}


void randNumber(int*& arr) {
	arr [0] = rand() % GamesAvailable;
	for (size_t i = 1; i < GamesAvailable; i++)
	{
		int number;
		do {
			number = rand() % GamesAvailable;
			//cout << number << endl;
		} while (!noRepeat(arr,number));
		arr[i] = number;

	}
	
}

Game fillGames(Game*& games, int userGames) {
	randNumber(arrNumbers);
	for (size_t i = 0; i < userGames; i++)
	{
		games[i].name = GameNames[arrNumbers[i]];
		games[i].hoursPlayed = rand() % 2000;
		games[i].raiting = rand() % 10;
		games[i].memoryNeeded = rand() % (120-10)+10;
		games[i].newGame = rand() % 2;
		games[i].achivements = rand() % 100;
		games[i].instaled = rand() % 2;
	}
	return *games;
}

void Game::ShowGame() {
	if (newGame)cout << "НОВИНКА!!" << endl;
	cout <<name << endl;
	cout << "Вы играли: " << hoursPlayed << " часов" << endl;
	cout << "Достижений выполнено: " << achivements << " %" << endl;
	cout << "Рейтинг: " << raiting << endl;
	cout << "Памяти требуется: " << memoryNeeded << endl << endl;
}

