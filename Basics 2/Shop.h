#pragma once
#include <string>
#include <list>
#include "Item.h"

using namespace std;

class Shop
{
public:
	Shop(string name, int money);

	void printShop();
	bool canAffordItem(string name, int money);
	bool purchaseItem(string name, Item &newItem);
	void addItem(Item newItem);

	void addMoney(int money) { _money += money; }

	//Getters
	string getName() { return _name; }
	int getMoney() { return _money;  }

private:
	string _name;
	list<Item> _items;
	int _money;

};

