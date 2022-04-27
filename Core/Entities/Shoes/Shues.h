#pragma once
#include "../../Lib/Lib.h"

struct Shoes {
	string modelName;
	int size;
	double price;

	
	void shoePrint();
	void shoeFill();
};
void shoeSearch(string modelName, int size, Shoes* arr, int arrSize);
