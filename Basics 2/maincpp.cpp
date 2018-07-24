#include <iostream>
#include <string>
#include "Player.h"
#include "Shop.h"

using namespace std;

void initShops(list<Shop> &shops);
void initPlayer(Player &player);
void enterShop(Player &player, Shop &shop);

int main()
{
	list<Shop> shops;
	list<Shop>::iterator lit;
	Player player;
	string shopName;

	initPlayer(player);
	initShops(shops);

	// Tells us when game is over
	bool isDone = false;

	while (isDone == false) {
		cout << "\nShops:\n";
		int i = 1;
		for (lit = shops.begin(); lit != shops.end(); lit++) {
			cout << i << ". " << (*lit).getName() << endl;
			i++;
		}

		cout << "\nYour journey will be hard, you should buy some equipment before you go.\nWhat store would you like to enter? \n";

		getline(cin, shopName);

		cout << endl;

		bool validShop = false;

		for (lit = shops.begin(); lit != shops.end(); lit++) {
			if ((*lit).getName() == shopName) {
				enterShop(player, (*lit));
				validShop = true;
			}
		}

		if (validShop == false) {
			cout << "Where is that?\n";
			system("PAUSE");
		}
}

	system("PAUSE");
	return 0;
}


void initShops(list<Shop> &shops)
{
	shops.push_back(Shop("Malhorn Market", 500));
	shops.back().addItem(Item("Enchantment Stone: Fire", 125));
	shops.back().addItem(Item("Enchantment Stone: Water", 100));
	shops.back().addItem(Item("Enchantment Stone: Lightning", 150));
	shops.back().addItem(Item("Enchantment Stone: Earth", 85));


	shops.push_back(Shop("Tavern Fall Inn", 300));
	shops.back().addItem(Item("Steak", 20));
	shops.back().addItem(Item("Bandages", 15));
	shops.back().addItem(Item("Vitality Elixr", 50));
	shops.back().addItem(Item("Mana Elixr", 50));


	shops.push_back(Shop("Daderic Wares\n", 1000));
	shops.back().addItem(Item("Knights Bane", 270));
	shops.back().addItem(Item("Yimir's Club", 340));
	shops.back().addItem(Item("Steel Sword", 70));
	shops.back().addItem(Item("Nimbus", 360));
}

void initPlayer(Player &player)
{
	cout << "What is your name young travler?\n";
	string name;
	getline(cin, name);
	player.init(name, 100);

	player.addItem(Item("Battle Axe", 5));
}

void enterShop(Player &player, Shop &shop)
{

	bool isDone = false;
	char input;
	string itemName;
	Item newItem("NO ITEM", 0);

	while (isDone == false) {
		shop.printShop();
		player.printInventory();

		cout << "Would you like to buy or sell? Enter Q to quit. (B/S): ";
		cin >> input;
		cin.ignore(64, '\n');
		cin.clear();

		if (input == 'Q' || input == 'q') isDone = true; // Quit

		if (input == 'B' || input == 'b') { // Buying
			cout << "Enter the item you would like to buy: ";
			getline(cin, itemName);

			if (shop.canAffordItem(itemName, player.getMoney())) {

				if (shop.purchaseItem(itemName, newItem) == true) {
					player.addMoney(-newItem.getValue());
					player.addItem(newItem);
					shop.addMoney(newItem.getValue());
				}
				else {
					cout << "I dont know what that is...";
					system("PAUSE");
				}
			}
			else {
				cout << "You dont have enough for that.\n";
				system("PAUSE");
			}

		}
		else { // Selling
			cout << "Enter the item you would like to sell: ";
			getline(cin, itemName);

			if (player.canAffordItem(itemName, shop.getMoney())) {

				if (player.removeItem(itemName, newItem) == true) {
					shop.addMoney(-newItem.getValue());
					shop.addItem(newItem);
					player.addMoney(newItem.getValue());
				}
				else {
					cout << "I dont know what that is...";
					system("PAUSE");
				}
			}
			else {
				cout << "The shop doesnt have enough for that.\n";
				system("PAUSE");
			}
		}
 
	}
}