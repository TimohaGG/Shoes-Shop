#pragma once
#include "../../Core/Entities/Shop/Shop.h"

struct Menu {
	Menu() {
		
		int shopsAmount = 0;
		cout << "Введите количество магазинов:   ";
		cin >> shopsAmount;
		Shop* ArrShops = new Shop[shopsAmount];
		
		CLEAR;
		while (true) {
			
			cout << "<---------------------------Меню-------------------------->" << endl;
			cout << "1. Вывод магазина по имени" << endl;
			cout << "2. Вывод магазина по геолокации" << endl;
			cout << "3. Поиск определенного продавца в сети магазинов" << endl;
			cout << "4. Поиск определенной пары обуви в сети магазинов" << endl;
			cout << "5. Заказ определенной пары обуви из одного магазина в другой" << endl;
			cout << "<--------------------------------------------------------->" << endl;
			int choise;
			cin >> choise;
			CLEAR;
			
			switch (choise) {
			case 1: {
				cout << "Список магазинов: "<<endl;
				ShowShops(ArrShops, shopsAmount);
			}break;
			case 2: {
				for (size_t i = 0; i < shopsAmount; i++)
				{
					cout << i + 1 << ". ";
					ArrShops[i].ShopLocation();
				}
			}break;
			case 3: {
				bool found = false;
				cout << "Какого продавца хотите найти?"<<endl;
				string nameFind;
				cin.ignore();
				getline(cin,nameFind);
				cout << "Продавец "<<nameFind<<" доступен в таких магазинах:"<<endl;
				for (size_t i = 0; i < shopsAmount; i++)
				{
					for (size_t j = 0; j < ArrShops[i].SellerArrSize; j++)
					{
						if (nameFind == ArrShops[i].SellersArr[j].name) {
							ArrShops[i].ShopName();
							found = true;
						}
					}
				}
				if (!found)cout << "	Упс. Такого продавца нигде нету(" << endl;
			}break;
			case 4: {
				cin.ignore();
				cout << "Введите модель для поиска: ";
				string name;
				getline(cin, name);
				cout << endl<<"Введите размер: ";
				int size;
				cin >> size;
				for (size_t i = 0; i < shopsAmount; i++)
				{
					shoeSearch(name,size,ArrShops[i]);
				}
			}break;
			case 5: {
				cout << "Из какого магазина доставить обувь?"<<endl;
				ShowShops(ArrShops, shopsAmount);
				int ShopToOrderI;
				cin >> ShopToOrderI;
				cout << "Какую обувь доставить?" << endl;
				int ShoeToOrderI;
				ShowShoes(ArrShops[ShopToOrderI].arrShoes, ArrShops[ShopToOrderI].ArrShoesSize);
				cin >> ShoeToOrderI;
				CLEAR;
				cout << "Куда доставить?";
				ShowShops(ArrShops, shopsAmount);
				int ShopToDeliverI;
				cin >> ShopToDeliverI;
				OrderShoes(ArrShops[ShopToOrderI], ArrShops[ShopToDeliverI], ShoeToOrderI);
				
				PAUSE;
			}break;
			}
			PAUSE;
			CLEAR;
		}
	}
};