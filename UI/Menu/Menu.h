#pragma once
#include "../../Core/Model/Model.h"

struct Menu {
	Menu() {
		createShop shop;
		while (true) {
			
			cout << "<--------------------------------------------------------->" << endl;
			cout << "1. Вывод магазина по имени" << endl;
			cout << "2. Вывод магазина по геолокации" << endl;
			cout << "3. Поиск определенного продавца в сети магазинов" << endl;
			cout << "4. Поиск определенной пары обуви в сети магазинов" << endl;
			cout << "5. Заказ определенной пары обуви из одного магазина в другой" << endl;
			cout << "<--------------------------------------------------------->" << endl;
			int choise;
			cin >> choise;
			switch (choise) {
			case 1: {
				for (size_t i = 0; i < shop.shopsAmount; i++)
				{
					shop.ArrShops[i].ShopName();
				}
			}break;
			case 2: {
				for (size_t i = 0; i < shop.shopsAmount; i++)
				{
					shop.ArrShops[i].ShopLocation();
				}
			}break;
			case 3: {}break;
			case 4: {
				cin.ignore();
				cout << "Введите модель для поиска: ";
				string name;
				getline(cin, name);
				cout << endl<<"Введите размер: ";
				int size;
				cin >> size;
				for (size_t i = 0; i < shop.shopsAmount; i++)
				{
					
					shoeSearch(name,size,shop.ArrShops[i]);
				}
			}break;
			case 5: {}break;
			}
		}
	}
};