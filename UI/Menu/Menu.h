#pragma once
#include"../../Core/Entities/User/User.h"
void Shop(User a);
void Library(User a);
void Community(User a);
void Profile(User a);

struct Menu {
	Menu() {
		
		//gamesAvailable = GetMaxGames();
		
		usersAmount = GetUsersAmount();
		userNames = new string[usersAmount];
		GetGamesNames(gamesAvailableArr);
		GetUsersNames(userNames);
		
		int* arrNumbersUserNames = new int[usersAmount];
		randNumberUsernames(arrNumbersUserNames,  usersAmount);
	
		User* user1=new User[usersAmount];
		for (size_t i = 0; i < usersAmount; i++)
		{
			user1[i].fillUser(gamesAvailableArr);
		}
		FillUsernames(user1, userNames, arrNumbersUserNames, usersAmount);
		//int index= Login(user1, usersAmount);
		int index=Registration(user1, usersAmount);
		//Login(user1, usersAmount);

		void(*menu[3])(User user1) {Shop,Library, Profile};
		while (true) {
			cout << "<----------Steam---------->" << endl;
			cout << "1. Магазин" << endl
				<< "2. Библиотека" << endl
				<< "4. Профиль" << endl
				<< "0. Выход" << endl;
			int choise;
			do
			{
				cin >> choise;
			} while (choise < 0 || choise>3);
			if (choise == 0) {
				exit(0);
			}
			else {
				CLEAR;
				menu[choise - 1](user1[index]);
			}
		}
		
	}
	
};


void Shop(User user1) {
	while (true) {
		cout << "<----------Shop---------->" << endl;
		cout << "1. Популярное" << endl
			<< "2. Рекомендации" << endl
			<< "3. Новинки" << endl
			<< "0. Выход" << endl;
		void(*menuShop[3])(User user1) { ShowGamesPopular, ShowGamesRecomendations, ShowGamesNew };
		int choise;
		do
		{
			cin >> choise;
		} while (choise < 0 || choise>3);
		if (choise != 0) {
			CLEAR;
			menuShop[choise - 1](user1);
			
		}
		else {
			break;
		}
		PAUSE;
		CLEAR;
	}
	
	CLEAR;
}





void Library(User user1) {
	while (true) {
		cout << "<----------Library---------->" << endl;
		cout << "1. Библиотека" << endl
			<< "2. Загрузки" << endl
			<< "0. Выход" << endl;
		void(*menuLibrary[2])(User user1) { ShowGames, LibraryMenu };
		int choise;
		do
		{
			cin >> choise;
		} while (choise < 0 || choise>2);
		if (choise != 0) {
			CLEAR;
			menuLibrary[choise - 1](user1);

		}
		else {
			break;
		}
		PAUSE;
		CLEAR;
	}
	CLEAR;
	
}


void Profile(User user1) {
	cout << "<----------Profile---------->" << endl;
	cout << "1. Профиль" << endl
		<< "2. Друзья" << endl
		<< "0. Выход" << endl;
	void(*menuProfile[3])(User a) {ShowProfile, };
	
}
