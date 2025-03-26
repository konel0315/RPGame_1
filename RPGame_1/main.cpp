#include <vector>
#include "Item.h"
#include <ctime>  

int clear = 0;
class Inventory {
public:
	vector<Item*> Exist;
	vector<Item*> PInventory;
	struct Pstatus
	{
	string name = "��ö��";
	int HP = 100;
	int MP = 100;
	int attack = 0;
	int defense = 0;
	};
	Pstatus playerStatus;
	Inventory() {}
	void status(string name,int hp,int mp,int attack,int defense) {
		playerStatus.name = name;
		playerStatus.HP = hp;
		playerStatus.MP = mp;
		playerStatus.attack = attack;
		playerStatus.defense = defense;
	};
	void showStatus() {
		cout << endl << "[ �÷��̾� ���� ]\n" << "�̸� : " << playerStatus.name << endl << "HP : " << playerStatus.HP << ", MP : " << playerStatus.MP << endl << "���ݷ� : " << playerStatus.attack << " ���� : " << playerStatus.defense << endl;
	}
	Item* serch() {
		
		int random_num = rand() % Exist.size();
		cout << endl << "[ ���ο� ������ �߰�! ]\n";
		Weapon* weapon = dynamic_cast<Weapon*>(Exist[random_num]);
		Consumable* consumable = dynamic_cast<Consumable*>(Exist[random_num]);
		Armor* armor = dynamic_cast<Armor*>(Exist[random_num]);;
		if (weapon) {
			cout << "-" << Exist[random_num]->name << " ���ݷ� +" << weapon->attack << endl;
		}
		if (consumable) {
			cout << "-" << Exist[random_num]->name << " Hp +" << consumable->hp << " Mp +" << consumable->mp << endl;
		}
		if (armor) {
			cout << "-" << Exist[random_num]->name << " ���� +" << armor->defense << endl;
		}
		return Exist[random_num];
	
	}
	void addItem(Item* item) {
		PInventory.push_back(item);
	}
	void exitItem(Item* item) {
		Exist.push_back(item);
	}
	void useItem(const string& itemname) {
		for (int i = 0;i < PInventory.size();i++) {
			if (PInventory[i]->name == itemname) {//�������� ������ �ϴ� addItem�� �ϰ� ���� �Ⱦ���� ������ ������ �����ϰ� ����
				Consumable* consumable = dynamic_cast<Consumable*>(PInventory[i]);
				if (consumable) {
					playerStatus.HP += consumable->hp; 
					playerStatus.MP += consumable->mp;
					PInventory.erase(PInventory.begin() + i);
					break;
				}
			}
		}
	
	}

	void equipItem(const string& itemName) {
		for (int i = 0;i < PInventory.size();i++) {
			if (PInventory[i]->name == itemName) {//�������� ������ �ϴ� addItem�� �ϰ� ���� �Ⱦ���� ������ ������ �����ϰ� ����
				Weapon* weapon = dynamic_cast<Weapon*>(PInventory[i]);
				if (weapon) {
					playerStatus.attack += weapon->attack; 
					PInventory.erase(PInventory.begin() + i);
					break;
				}
				Armor* armor = dynamic_cast<Armor*>(PInventory[i]);
				if (armor) { 
					playerStatus.defense += armor->defense; 
					PInventory.erase(PInventory.begin() + i);
					break;
				}
			}
		}
	}

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
	srand(time(0));
	Weapon* WeaponPtr = new Weapon();//����
	Consumable* ConsumablePtr = new Consumable();//�Ҹ�ǰ


	WeaponPtr->name = "���";
	WeaponPtr->attack = 5;
	ConsumablePtr->name = "���� ����";
	ConsumablePtr->hp = 5;

	Inventory PInven;
	PInven.exitItem(WeaponPtr);
	PInven.exitItem(ConsumablePtr);

	while (clear==0) {

		PInven.showStatus();
		Item *ImsiPtr = PInven.serch();
		PInven.addItem(ImsiPtr);
		cout << endl << "[ �ൿ�� �����ϼ��� ]" << endl;
		cout << "1. ������ ���" << endl;
		cout << "2. ������ ����" << endl;
		cout << "3. �κ��丮 Ȯ��" << endl ;
		int num = 0;
		cin >> num;
		if (num==1) {
			Weapon* weapon = dynamic_cast<Weapon*>(ImsiPtr);
			Consumable* consumable = dynamic_cast<Consumable*>(ImsiPtr);
			Armor* armor = dynamic_cast<Armor*>(ImsiPtr);;
			if (weapon) {
				cout << endl << "[ ���� ���� ]" << endl;
				cout << "-" << ImsiPtr->name <<" ���� �Ϸ� " << "( ���ݷ� +" << weapon->attack <<")" << endl;
				PInven.equipItem(ImsiPtr->name);
			}
			if (consumable) {
				cout << endl << "[  ��� ���� ]" << endl;
				cout << "-" << ImsiPtr->name << " ��� �Ϸ� " << "( Hp +" << consumable->hp << ")" << "( Mp +" << consumable->mp << ")" <<endl;
				PInven.useItem(ImsiPtr->name);
			}
			if (armor) {
				cout << endl << "[ ���� ���� ]" << endl;
				cout << "-" << ImsiPtr->name << " ���� �Ϸ� " << "( ���ݷ� +" << armor->defense << ")" << endl;
				PInven.equipItem(ImsiPtr->name);
			}
		
		}
		//else if (num == 2) {}
		else if (num == 3) { PInven.displayInventory(); }
		else {}
	}


	delete WeaponPtr;
	delete ConsumablePtr;
}