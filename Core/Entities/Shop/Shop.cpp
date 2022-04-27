#include"Shop.h"
void Shop::ShopName() {
	cout << "<!-----------------!>"<<endl;
	cout << "Название магазина: " << name << endl;
	
}

void Shop::ShopLocation() {
	cout << "<!~~~~~~~~~~~~~~~~~~~!>" << endl;
	cout << "Местоположение магазина:"<<location<<endl;
	
}

void SellerSearch(string name, Shoes* arrShoes, int arrSize) {
	bool found = false;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (name == arrShoes[i].modelName) {
			arrShoes[i].shoePrint();
			found = true;
		}
	}
	if (!found)cout << "Совпадений не найдено!" << endl;
}

void fillShoes(Shoes* arrShoes, int arrSize) {
	
	for (size_t i = 0; i < arrSize; i++)
	{
		
		arrShoes[i].shoeFill();
		cin.ignore();
	}
}

void showShoes(Shoes* arrShoes, int arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		arrShoes[i].shoePrint();
	}
}

void Shop::SetShopNameLocation() {
	cout << "Введите название магазина: ";
	cin >> name;
	cout << "Введите расположение магазина: ";
	cin >> location;
}

void shoeSearch(string modelName, int size, Shop ArrShops) {

	bool found = false;
	for (size_t i = 0; i < ArrShops.ArrSize; i++)
	{
		if (ArrShops.arrShoes[i].modelName == modelName && ArrShops.arrShoes[i].size == size) {
			ArrShops.ShopName();
			ArrShops.arrShoes[i].shoePrint();
			cout << "<------------------------>" << endl;
			found = true;
		}

	}
	if (!found)cout << "Такой модели нету!" << endl;
}