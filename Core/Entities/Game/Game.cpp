#include"Game.h"
int GetMaxGames() {
	string buf;
	ifstream f1("../Inf/GamesNames.txt", ios::in);
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

int GetUsersAmount() {
	string buf;
	ifstream f1("../Inf/UserNames.txt", ios::in);
	if (f1.is_open()) {
		while (getline(f1, buf)) {
			usersAmount++;
		}
		f1.close();
	}
	else {
		cout << "Error opening file!!" << endl;
	}

	return usersAmount;
}

string* GetGamesNames(string *&arr) {
	ifstream f2("../Inf/GamesNames.txt", ios::in);
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

string* GetUsersNames(string*& arr) {
	ifstream f2("../Inf/UserNames.txt", ios::in);
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
	if (newGame)cout << "Новинка!!!"<<endl;
	cout << name << endl;
	/*cout << "Часов потрачено: " << hoursPlayed << endl;
	cout << "Достижений выполнено: " << achivements << " %" << endl;*/
	cout << "Рейтинг: " << raiting << endl;
	cout << "Загрузки: " << downloads << endl;
	cout << "Памяти требуется: " << memoryNeeded << endl << endl;


	/*PrintWord(name);
	PrintPhrase("Часов потрачено: ",hoursPlayed);
	PrintPhrase("Достижений выполнено: ", achivements);
	PrintPhrase("Рейтинг: ", raiting);
	PrintPhrase("Загрузки: ", downloads);
	PrintPhrase("Памяти требуется: ", memoryNeeded);
	PrintWord("<------------------------->");
	cout << endl << endl;*/
	
}