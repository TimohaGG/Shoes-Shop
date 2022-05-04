#pragma once
#include"../../Core/Entities/User/User.h"
void Shop(User a);
void Library(User a);
void Community(User a);
void Profile(User a);

struct Menu {
	Menu() {
		
		gamesAvailable = GetMaxGames();
		gamesAvailableArr = new string[gamesAvailable];
		GetGamesNames(gamesAvailableArr);
		User a;
		void(*menu[4])(User a) {Shop,Library,Community, Profile};
		while (true) {
			cout << "<----------Steam---------->" << endl;
			cout << "1. Магазин" << endl
				<< "2. Библиотека" << endl
				<< "3. Сообщество" << endl
				<< "4. Профиль" << endl
				<< "0. Выход" << endl;
			int choise;
			do
			{
				cin >> choise;
			} while (choise < 0 || choise>4);
			if (choise == 0) {
				exit(0);
			}
			else {
				CLEAR;
				menu[choise - 1](a);
			}
		}
		
	}
	
};


void Shop(User a) {
	while (true) {
		cout << "<----------Shop---------->" << endl;
		cout << "1. Популярное" << endl
			<< "2. Рекомендации" << endl
			<< "3. Новинки" << endl
			<< "0. Выход" << endl;
		void(*menuShop[3])(User a) { ShowGamesPopular, ShowGamesRecomendations, ShowGamesNew };
		int choise;
		do
		{
			cin >> choise;
		} while (choise < 0 || choise>3);
		if (choise != 0) {
			CLEAR;
			menuShop[choise - 1](a);
			
		}
		else {
			break;
		}
		PAUSE;
		CLEAR;
	}
	
	CLEAR;
}





void Library(User a) {
	cout << "<----------Library---------->" << endl;
	cout << "1. Библиотека" << endl
		<< "2. Загрузки" << endl
		<< "0. Выход" << endl;
	void(*menuLibrary[2])() {};
	system("pause");
}
void Community(User a) {
	cout << "<----------Community---------->" << endl;
	cout << "1. Торговая площадка" << endl
		<< "0. Выход" << endl;
	system("pause");
}
void Profile(User a) {
	cout << "<----------Profile---------->" << endl;
	cout << "1. Профиль" << endl
		<< "2. Друзья" << endl
		<< "3. Инвентарь" << endl
		<< "0. Выход" << endl;
	void(*menuProfile[3])() {};
	system("pause");
}
