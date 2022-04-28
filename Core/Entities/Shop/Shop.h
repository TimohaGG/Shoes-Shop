#pragma once
#include "../Seller/Seller.h"
struct Shop {
	
	Shop() {
		
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
void shoeSearch(string modelName, int size, Shop ArrShops);
void SellerSearch(string name, Shoes* arrShoes, int arrSize);