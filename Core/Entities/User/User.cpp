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
			return a.userGames[0];
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



int Login(User* a, int usersAmount) {
	bool loginOk = false;
	while (true) {
		cout << "Введите логин: " << endl;
		string login;
		getline(cin, login);
		int i = 0;
		for (; i < usersAmount; i++)
		{
			if (a[i].UserName == login) {
				loginOk = true;
				cout << "Введите пароль: " << endl;
				string password;
				getline(cin, password);
				if (a[i].password == password) {
					
					PAUSE;
					CLEAR;
					return i;
				}
				else {
					cout << "Неверный пароль!!!" << endl;
					PAUSE;
					CLEAR;
				}
				break;
			}
			
		}
		if (!loginOk) {
			cout << "Такого логина нету!" << endl;
			PAUSE;
			CLEAR;
		}
	}
	
	
	
}

void randNumberUsernames(int*& arrNumbers, int usernamesAvailable) {
	arrNumbers[0] = rand() % usernamesAvailable;
	for (size_t i = 1; i < usernamesAvailable; i++)
	{
		int number;
		do {
			number = rand() % usernamesAvailable;
			//cout << number << endl;
		} while (!noRepeat(arrNumbers, number, usernamesAvailable));
		arrNumbers[i] = number;

	}
}

User* FillUsernames(User*& users, string* usernames, int* arrNumbers, int usersAmount) {
	for (size_t i = 0; i < usersAmount; i++)
	{
		users[i].UserName = usernames[arrNumbers[i]];
	}
	return users;
}

int Registration(User*& users, int& usersAmount) {
	User* newUsers = new User[usersAmount+1];
	for (size_t i = 0; i < usersAmount; i++)
	{
		newUsers[i] = users[i];
	}
	cout << "Введите логин"<<endl;
	getline(cin, newUsers[usersAmount].UserName);
	cout << "Введите пароль"<<endl;
	getline(cin,newUsers[usersAmount].password);
	newUsers[usersAmount].userGamesAmount = 0;
	delete[] users;
	users = new User[usersAmount + 1];
	for (size_t i = 0; i < usersAmount+1; i++)
	{
		users[i] = newUsers[i];
	}
	usersAmount++;
	delete[] newUsers;
	return usersAmount-1;
}

void User::fillUser(string* gamesAvailableArr){
	randNumber(arrNumbersGameNames, gamesAvailable, userGamesAmount);

	password = "111";
	for (size_t i = 0; i < userGamesAmount; i++)
	{

		userGames[i].name = gamesAvailableArr[arrNumbersGameNames[i]];
		userGames[i].hoursPlayed = rand() % 2000;
		userGames[i].raiting = rand() % 10;
		userGames[i].memoryNeeded = rand() % (120 - 10) + 10;
		userGames[i].newGame = rand() % 2;
		userGames[i].achivements = rand() % 100;
		userGames[i].instaled = rand() % 2;
		userGames[i].downloads = rand() % (1000000 - 90000) + 70000;
	}
	}

void ShowProfile(User a) {
	cout << "Имя: " << a.UserName << endl;
	cout << "Пароль: " << a.password << endl;
	cout << "Всего игр: " << a.userGamesAmount << endl;
	cout << "Библиотека: "<<endl;
	for (size_t i = 0; i < a.userGamesAmount; i++)
	{
		cout <<i+1<<". " << a.userGames[i].name << endl;
	}
}


