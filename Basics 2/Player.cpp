#include "Player.h"
#include <iostream>


Player::Player()
{
}

void Player::init(string name, int money)
{
	_name = name;
	_money = money;
}

void Player::printInventory()
{
	cout << "*** " << _name << "'s inventory ***\n\n";
	cout << _money << " Gold coins\n\n";
	list<Item>::iterator lit;

	int i = 0;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << " Price: " << (*lit).getValue() << " Gold coins" << endl;
		i++;
	}
}

bool Player::canAffordItem(string name, int money)
{
	list<Item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getName() == name) {
			if ((*lit).getValue() <= money) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}


bool Player::removeItem(string name, Item &newItem)
{
	list<Item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getName() == name) {
			newItem = (*lit);
			(*lit).removeOne();
			if ((*lit).getCount() == 0) {
				_items.erase(lit);
			}
			return true;
		}
	}
	return false;
}

void Player::addItem(Item newItem)
{
	list<Item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getName() == newItem.getName()) {
			(*lit).addOne();
			return;
		}
	}

	_items.push_back(newItem);
}
