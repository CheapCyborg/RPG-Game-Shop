#pragma once
#include <string>
#include <list>
#include "Item.h"

using namespace std;


class Player
{
public:
	Player();

	// Initialize Player
	void init(string name, int money);

	void printInventory();
	bool canAffordItem(string name, int money);

	bool removeItem(string name, Item &newItem);
	void addItem(Item newItem);

	void addMoney(int money) { _money += money; }

	// Getter
	int getMoney() { return _money;  }
	void subtractMoney(int amount) { _money -= amount; }

private:
	string _name;
	list<Item> _items;
	int _money;
};

