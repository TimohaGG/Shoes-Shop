#pragma once
#include "../Seller/Seller.h"
struct Shop {
	
	Shop() {	
#ifndef DEBUG
		SellersArr = new Seller[SellerArrSize];
		SetShopNameLocation();
		cout << "Сколько пар обуви добавить?" << endl;
		cin >> ArrShoesSize;

		arrShoes = new Shoes[ArrShoesSize];
		cin.ignore();
		for (size_t j = 0; j < ArrShoesSize; j++)
		{
			arrShoes[j].shoeFill();
			if (j == 0) {
				SellersArr[0].name = arrShoes[j].modelName;
			}
			else {
				addSeller(arrShoes[j].modelName, SellersArr, SellerArrSize);
			}
		}
#endif // DEBUG

#ifdef DEBUG
		SellerArrSize = 3;
		SellersArr = new Seller[SellerArrSize]{"Adidas","Puma","Nike"};
		SetShopNameLocation();
		ArrShoesSize = 4;
		arrShoes = new Shoes[ArrShoesSize];
		arrShoes[0].modelName = "Adidas";
		arrShoes[0].size = 32;
		arrShoes[0].price = rand()%1000;
		arrShoes[1].modelName = "Adidas";
		arrShoes[1].size = 30;
		arrShoes[1].price = rand() % 1000;
		arrShoes[2].modelName = "Puma";
		arrShoes[2].size = 41;
		arrShoes[2].price = rand() % 1000;
		arrShoes[3].modelName = "Nike";
		arrShoes[3].size = 43;
		arrShoes[3].price = rand() % 1000;
		
#endif // !DEBUG

	}
	int SellerArrSize = 1;
	Seller* SellersArr;
	string name;
	string location;
	int ArrShoesSize = 0;
	Shoes* arrShoes;
	
	void SetShopNameLocation();
	void ShopName();
	void ShopLocation();
	

};
void ShowShops(Shop* ArrShops, int size);
void shoeSearch(string modelName, int size, Shop ArrShops);
void SellerSearch(string name, Shoes* arrShoes, int arrSize);
void OrderShoes(Shop& arrToOrder, Shop& arrToDeliver, int ShoeToOrderI);