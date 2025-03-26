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
	string name = "김철수";
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
		cout << endl << "[ 플레이어 스탯 ]\n" << "이름 : " << playerStatus.name << endl << "HP : " << playerStatus.HP << ", MP : " << playerStatus.MP << endl << "공격력 : " << playerStatus.attack << " 방어력 : " << playerStatus.defense << endl;
	}
	Item* serch() {
		
		int random_num = rand() % Exist.size();
		cout << endl << "[ 새로운 아이템 발견! ]\n";
		Weapon* weapon = dynamic_cast<Weapon*>(Exist[random_num]);
		Consumable* consumable = dynamic_cast<Consumable*>(Exist[random_num]);
		Armor* armor = dynamic_cast<Armor*>(Exist[random_num]);;
		if (weapon) {
			cout << "-" << Exist[random_num]->name << " 공격력 +" << weapon->attack << endl;
		}
		if (consumable) {
			cout << "-" << Exist[random_num]->name << " Hp +" << consumable->hp << " Mp +" << consumable->mp << endl;
		}
		if (armor) {
			cout << "-" << Exist[random_num]->name << " 방어력 +" << armor->defense << endl;
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
			if (PInventory[i]->name == itemname) {//아이템을 얻으면 일단 addItem을 하고 이후 안쓸경우 보관과 삭제가 가능하게 하자
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
			if (PInventory[i]->name == itemName) {//아이템을 얻으면 일단 addItem을 하고 이후 안쓸경우 보관과 삭제가 가능하게 하자
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
		else cout << "제거할 아이템이 존재하지 않습니다.";
	}

};

int main() {
	srand(time(0));
	Weapon* WeaponPtr = new Weapon();//무기
	Consumable* ConsumablePtr = new Consumable();//소모품


	WeaponPtr->name = "대검";
	WeaponPtr->attack = 5;
	ConsumablePtr->name = "빨간 물약";
	ConsumablePtr->hp = 5;

	Inventory PInven;
	PInven.exitItem(WeaponPtr);
	PInven.exitItem(ConsumablePtr);

	while (clear==0) {

		PInven.showStatus();
		Item *ImsiPtr = PInven.serch();
		PInven.addItem(ImsiPtr);
		cout << endl << "[ 행동을 선택하세요 ]" << endl;
		cout << "1. 아이템 사용" << endl;
		cout << "2. 아이템 장착" << endl;
		cout << "3. 인벤토리 확인" << endl ;
		int num = 0;
		cin >> num;
		if (num==1) {
			Weapon* weapon = dynamic_cast<Weapon*>(ImsiPtr);
			Consumable* consumable = dynamic_cast<Consumable*>(ImsiPtr);
			Armor* armor = dynamic_cast<Armor*>(ImsiPtr);;
			if (weapon) {
				cout << endl << "[ 장착 성공 ]" << endl;
				cout << "-" << ImsiPtr->name <<" 장착 완료 " << "( 공격력 +" << weapon->attack <<")" << endl;
				PInven.equipItem(ImsiPtr->name);
			}
			if (consumable) {
				cout << endl << "[  사용 성공 ]" << endl;
				cout << "-" << ImsiPtr->name << " 사용 완료 " << "( Hp +" << consumable->hp << ")" << "( Mp +" << consumable->mp << ")" <<endl;
				PInven.useItem(ImsiPtr->name);
			}
			if (armor) {
				cout << endl << "[ 장착 성공 ]" << endl;
				cout << "-" << ImsiPtr->name << " 장착 완료 " << "( 공격력 +" << armor->defense << ")" << endl;
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