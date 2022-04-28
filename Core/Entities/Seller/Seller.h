#pragma once
#include "../Shoes/Shues.h"
struct Seller {
	string name;
};

Seller addSeller(string name, Seller*& SellersArr, int& size);
Seller sellerSearch();