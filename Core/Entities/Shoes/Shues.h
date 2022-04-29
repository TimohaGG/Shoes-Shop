#pragma once
#include "../../Lib/Lib.h"

struct Shoes {
	string modelName;
	int size;
	double price;
	void shoePrint();
	void shoeFill();
};
void ShowShoes(Shoes* arr, int size);
