#include"Shop.h"
void Shop::ShopName() {
	cout <<name<<endl;	
}

void Shop::ShopLocation() {
	cout <<location << endl;
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
	for (size_t i = 0; i < ArrShops.ArrShoesSize; i++)
	{
		if (ArrShops.arrShoes[i].modelName == modelName && ArrShops.arrShoes[i].size == size) {
			ArrShops.ShopName();
			ArrShops.arrShoes[i].shoePrint();
			found = true;
		}

	}
	if (!found)cout << "Такой модели нету!" << endl;
}

void ShowShops(Shop* ArrShops, int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		ArrShops[i].ShopName();
	}
}

void OrderShoes(Shop& arrToOrder, Shop& arrToDeliver, int ShoeToOrderI){
	//add new shoe
	Shoes* arrBuffer = new Shoes[arrToDeliver.ArrShoesSize+1];
	for (size_t i = 0; i < arrToDeliver.ArrShoesSize; i++)
	{
		arrBuffer[i] = arrToDeliver.arrShoes[i];
	}
	arrBuffer[arrToDeliver.ArrShoesSize] = arrToOrder.arrShoes[ShoeToOrderI];
	delete[] arrToDeliver.arrShoes;
	arrToDeliver.arrShoes = new Shoes[arrToDeliver.ArrShoesSize + 1];
	for (size_t i = 0; i < arrToDeliver.ArrShoesSize+1; i++)
	{
		arrToDeliver.arrShoes[i] = arrBuffer[i];
	}
	delete[] arrBuffer;
	arrToDeliver.ArrShoesSize++;
	//delete shoe

	arrBuffer = new Shoes[arrToOrder.ArrShoesSize - 1];
	for (size_t i = 0; i < arrToOrder.ArrShoesSize; i++)
	{
		if (i < ShoeToOrderI) {
			arrBuffer[i] = arrToOrder.arrShoes[i];
		}
		else if (i > ShoeToOrderI) {
			arrBuffer[i-1] = arrToOrder.arrShoes[i];
		}
	}
}

void ShowShopsAndInf(Shop* arrShop, int size) {
	for (size_t i = 0; i < size; i++)
	{
		arrShop[i].ShopName();
		arrShop[i].ShopLocation();
		for (size_t j = 0; j < arrShop[i].ArrShoesSize; j++)
		{
			arrShop[i].arrShoes[j].shoePrint();
		}
	}
}

