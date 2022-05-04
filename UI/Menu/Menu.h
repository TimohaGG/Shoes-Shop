#pragma once
#include"../../Core/Entities/User/User.h"
void Shop();
void Library();
void Community();
void Profile();

struct Menu {
	Menu() {
		gamesAvailable = GetMaxGames();
		gamesAvailableArr = new string[gamesAvailable];
		GetGamesNames(gamesAvailableArr);
		void(*menu[4])() {Shop,Library,Community, Profile};
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
				menu[choise - 1]();
			}
		}
		
	}
	
};

void Shop() {
	cout << "<----------Shop---------->" << endl;
	cout << "1. Популярное" << endl
		<< "2. Рекомендации" << endl
		<< "3. Статистика" << endl
		<< "0. Выход" << endl;
	void(*menuShop[3])() {Popular, Recomendations, Statistics};
	int choise;
	do
	{
		cin >> choise;
	} while (choise < 0 || choise>3);
	if (choise != 0) {
		menuShop[choise - 1]();
	}
	system("pause");
}

void Popular() {

}

void Recomendations() {

}

void Statistics() {

}



void Library() {
	cout << "<----------Library---------->" << endl;
	cout << "1. Библиотека" << endl
		<< "2. Загрузки" << endl
		<< "0. Выход" << endl;
	void(*menuLibrary[2])() {};
	system("pause");
}
void Community() {
	cout << "<----------Community---------->" << endl;
	cout << "1. Торговая площадка" << endl
		<< "0. Выход" << endl;
	system("pause");
}
void Profile() {
	cout << "<----------Profile---------->" << endl;
	cout << "1. Профиль" << endl
		<< "2. Друзья" << endl
		<< "3. Инвентарь" << endl
		<< "0. Выход" << endl;
	void(*menuProfile[3])() {};
	system("pause");
}
