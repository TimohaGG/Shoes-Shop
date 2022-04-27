#pragma once
#include "../Seller/Seller.h"
struct Shop {
	string name;
	string location;
	int ArrSize = 0;
	Shoes* arrShoes;
	void SetShopNameLocation();
	void ShopName();
	void ShopLocation();
	
};
void shoeSearch(string modelName, int size, Shop ArrShops);
void SellerSearch(string name, Shoes* arrShoes, int arrSize);