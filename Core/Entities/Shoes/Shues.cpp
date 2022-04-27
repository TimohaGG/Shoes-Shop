#include "Shues.h"

void Shoes::shoePrint() {
	cout << "<-------------------->"<<endl;
	cout << "Модель: " << modelName << endl;
	cout << "Размер: " << size << endl;
	cout << "Цена:   " << price << endl;
	cout << "<-------------------->" << endl;
}

void Shoes::shoeFill() {
	cout << "Введите модель        : ";
	getline(cin, modelName);
	cout << endl << "Введите размер: ";
	cin >> size;
	cout << endl << "Введите цену  : ";
	cin >> price;
	cout << endl;
}

void shoeSearch(string modelName, Shoes* arr, int arrSize) {
	bool found = false;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i].modelName == modelName) {
			arr[i].shoePrint();
		}

	}
	if (found)cout << "Такой модели нету!" << endl;
}

void shoeSearch(int size, Shoes* arr, int arrSize) {
	bool found = false;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i].size == size) {
			arr[i].shoePrint();
		}

	}
	if (found)cout << "Такого размера нету!" << endl;
}

void shoeSearch(double price, Shoes* arr, int arrSize){
	bool found = false;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i].price == price) {
			arr[i].shoePrint();
		}

	}
	if (found)cout << "Такой цены нету!" << endl;
}

