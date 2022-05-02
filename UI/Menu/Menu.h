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
			cout << "6. Показать магазины и товары"<<endl;
			cout << "0. Выход"<<endl;
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
				bool found = false;
				for (size_t i = 0; i < shopsAmount; i++)
				{
					if (ShoeSearch(name, size, ArrShops[i])) found = true;
				}
				if (!found)cout << "Такой модели нету!" << endl;
			}break;
			case 5: {
				int ShopToOrderI;
				do {
					cout << "Из какого магазина доставить обувь?" << endl;
					ShowShops(ArrShops, shopsAmount);
					
					cin >> ShopToOrderI;
					CLEAR;
				} while (ShopToOrderI>shopsAmount||ShopToOrderI<=0);
				CLEAR;
				
				int ShoeToOrderI;
				do{
				cout << "Какую обувь доставить?" << endl;
				ShowShoes(ArrShops[ShopToOrderI - 1].arrShoes, ArrShops[ShopToOrderI - 1].ArrShoesSize);
				cin >> ShoeToOrderI;
				CLEAR;
				} while (ShoeToOrderI> ArrShops[ShopToOrderI - 1].ArrShoesSize||ShoeToOrderI<=0);
				int ShopToDeliverI;
				do {
					cout << "Куда доставить?"<<endl;
					ShowShops(ArrShops, shopsAmount);
					cin >> ShopToDeliverI;
					CLEAR;
				} while (ShopToDeliverI == ShopToOrderI||ShopToDeliverI<=0||ShopToDeliverI>shopsAmount);
					
				OrderShoes(ArrShops[ShopToOrderI-1], ArrShops[ShopToDeliverI-1], ShoeToOrderI-1);
				cout << "Доставка осуществляется!"<<endl<<"Спасибо что пользуетесь нашими услугами))"<<endl;
				
			}break;
			case 6: {
				ShowShopsAndInf(ArrShops, shopsAmount);
				}break;
			default: {
				exit(0);
			}
			}

			
			PAUSE;
			CLEAR;
		}
	}
};