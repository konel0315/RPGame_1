#include <vector>
#include "Item.h"


class Inventory {
public:
	vector<Item*> PInventory;
	Inventory() {}
	void addItem(Item* item) {
		PInventory.push_back(item);
	}
	void useItem(const string& itemname) {}

	void equipItem(const string& itemName) {}

	void displayInventory() {
		system("cls");
		for (int i = 0; i < PInventory.size(); i++) {
			cout << i << " : " << PInventory[i]->name << "\n";
		}
	}
	void removeItem() {
		int i = -1;
		displayInventory();
		cin >> i;
		if (i >= 0 && i < PInventory.size()) {
			PInventory.erase(PInventory.begin() + i);
			displayInventory();
		}
		else cout << "������ �������� �������� �ʽ��ϴ�.";
	}

};

int main() {
	Weapon* WeaponPtr = new Weapon();//����
	Consumable* ConsumablePtr = new Consumable();//�Ҹ�ǰ
	WeaponPtr->name = "���";
	ConsumablePtr->name = "���� ����";
	Inventory PInven;
	PInven.addItem(WeaponPtr);
	PInven.addItem(ConsumablePtr);
	PInven.displayInventory();
	PInven.removeItem();
	delete WeaponPtr;
	delete ConsumablePtr;
}