#include "../Shop/Shop.h"
void Shoes::shoePrint() {
	
	cout << "Модель: " << modelName << endl;
	cout << "Размер: " << size << endl;
	cout << "Цена:   " << price << endl<<endl;
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
void ShowShoes(Shoes* arr,int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << "---------"<<i+1<<"---------"<<endl;
		arr[i].shoePrint();
	}
}




