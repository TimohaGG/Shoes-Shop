#include"Game.h"
extern string GameNames[10]{"Counter Strike: Global Offensive","Just Cause 3","GTA5","Far Cry 5","Little Nightmares","Geometry Dash","Raft","Pubg","Tomb Raider","Crossout"};
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

Game fillGames(Game*& games) {
	randNumber(arrNumbers);
	for (size_t i = 0; i < GamesAvailable; i++)
	{
		games[i].name = GameNames[arrNumbers[i]];
		games[i].hoursPlayed = rand() % 2000;
		games[i].raiting = rand() % 10;
		games[i].memoryNeeded = rand() % 100;
		games[i].newGame = rand() % 1;
		games[i].achivements = rand() % 100;
	}
	return *games;
}

void showGames(Game* games) {
	for (size_t i = 0; i < GamesAvailable; i++)
	{
		if (games[i].newGame)cout << "НОВИНКА!!"<<endl;
		cout << games[i].name << endl;
		cout << "Вы играли: " << games[i].hoursPlayed<<" часов" << endl;
		cout << "Достижений выполнено: " << games[i].achivements <<" %" << endl;
		cout << "Рейтинг: " << games[i].raiting << endl;
		cout << "Памяти требуется" << games[i].memoryNeeded << endl<<endl;
	
	}
}