#pragma once
#include "../Entities/Shop/Shop.h"
struct createShop {
	Shop* ArrShops;
	int shopsAmount = 0;
	createShop() {
		cout << "¬ведите количество магазинов:   ";
		cin >> shopsAmount;
		cin.ignore();
		ArrShops= new Shop[shopsAmount];
		for (size_t i = 0; i < shopsAmount; i++)
		{
			ArrShops[i].SetShopNameLocation();
			cout << "—колько пар обуви добавить?"<<endl;
			cin >> ArrShops[i].ArrSize;
			ArrShops[i].arrShoes = new Shoes[ArrShops[i].ArrSize];
			cin.ignore();
			for (size_t j = 0; j < ArrShops[i].ArrSize; j++)
			{
				ArrShops[i].arrShoes[j].shoeFill();
				
			}
			
		}
	}
	void showShops() {
		for (size_t i = 0; i < shopsAmount; i++)
		{
			ArrShops[i].ShopName();
			ArrShops[i].ShopLocation();
			for (size_t j = 0; j < ArrShops[i].ArrSize; j++)
			{
				ArrShops[i].arrShoes[j].shoePrint();
			}
		}
	}
};
