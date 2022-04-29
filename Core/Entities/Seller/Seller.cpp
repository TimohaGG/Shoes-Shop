#include "Seller.h"
Seller addSeller(string name, Seller*& SellersArr, int& size) {
	bool available = true;
	for (size_t i = 0; i < size; i++)
	{
		if (name == SellersArr[i].name) {
			available = false;
			break;
		}
	}
	if (available) {
		Seller* SellersArrTmp = new Seller[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			SellersArrTmp[i].name = SellersArr[i].name;
		}
		SellersArrTmp[size].name = name;
		delete[] SellersArr;
		SellersArr = new Seller[size + 1];
		for (size_t i = 0; i < size+1; i++)
		{
			SellersArr[i].name = SellersArrTmp[i].name;
		}
		delete[] SellersArrTmp;
		size++;
		
	}
	return* SellersArr;
}


