#include "Shues.h"
#include "../Shop/Shop.h"
void Shoes::shoePrint() {
	
	cout << "Модель: " << modelName << endl;
	cout << "Размер: " << size << endl;
	cout << "Цена:   " << price << endl;
	cout << "<-------------------->" << endl;
}

void Shoes::shoeFill() {
	cout << "Введите модель        : ";
	getline(cin, modelName);
	cout << "Введите размер: ";
	cin >> size;
	cout  << "Введите цену  : ";
	cin >> price;
	cin.ignore();
	CLEAR;
}




