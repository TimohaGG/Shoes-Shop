#pragma once
#include "../../Lib/Lib.h"

struct Shoes {
	string modelName;
	int size;
	double price;

	
	void shoePrint();
};
void shoeSearch(string modelName, Shoes* arr, int arrSize);
void shoeSearch(int size, Shoes* arr, int arrSize);
void shoeSearch(double price, Shoes* arr, int arrSize);
