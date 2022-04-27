#pragma once
#include "../Seller/Seller.h"
struct Shop {
	string name;
	string location;
	int Arrsize = 5;
	Shoes* arrShoes = new Shoes[Arrsize]{ {"Adidas",32,31.3}, 
		{"Puma",31,32.3},
		{"Adidas",30,33.3},
		{"Nike",34,34.3},
		{"Adidas",37,36.3}};
	void ShopName();
	void ShopLocation();
	
};