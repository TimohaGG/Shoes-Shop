#include"Game.h"
int GetMaxGames() {
	string buf;
	ifstream f1("../GamesInf/GamesNames.txt", ios::in);
	if (f1.is_open()) {
		while (getline(f1, buf)) {
			gamesAvailable++;
		}
		f1.close();
	}
	else {
		cout << "Error opening file!!"<<endl;
	}
	
	return gamesAvailable;
}

string* GetGamesNames(string *&arr) {
	ifstream f2("../GamesInf/GamesNames.txt", ios::in);
	if (f2.is_open()) {
		
		for (size_t i = 0; getline(f2, arr[i]); i++) {

		}
		f2.close();
	}
	else {
		cout << "Error openingfile!!" << endl;
	}
	return arr;
}

void Game::ShowGame() {
	if (newGame)cout << "НОВИНКА!!" << endl;
	cout << name << endl;
	cout << "Вы играли: " << hoursPlayed << " часов" << endl;
	cout << "Достижений выполнено: " << achivements << " %" << endl;
	cout << "Рейтинг: " << raiting << endl;
	cout << "Памяти требуется: " << memoryNeeded << endl << endl;
}