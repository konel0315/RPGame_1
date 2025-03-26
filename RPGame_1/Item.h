#pragma once
#include <iostream>
#include <string>
#include <ctime>  
#include <vector>
enum{
Tpye_Item,
Tpye_weapon,
Tpye_armor,
Tpye_consumable, 
Tpye_questItem,};
	
	
using namespace std;
class Item {
public:
	string name;
	int type = Tpye_Item;
	Item() {}
	virtual ~Item() {}
};

class Equip : public Item {
public:
	Equip() {}
	virtual ~Equip() {}
};

class Weapon : public Equip
{
public:

	virtual ~Weapon() {}
	//무기 이름
	short element;//무기 속성
	int attack = 0;
	Weapon(string itemName, int itemAttack) {
		type = Tpye_weapon;
		name = itemName;
		element = 0;
		attack = itemAttack;
	}
};

class Armor : public Equip {
public:

	virtual ~Armor() {}
	//무기 이름
	short element;//무기 속성
	int defense = 0;
	Armor(string itemName, int itemDefense) {
		name = itemName;
		type = Tpye_armor;
		element = 0;
		defense = itemDefense;
	}
};

class Consumable : public Item {
public:
	int hp = 0;
	int mp = 0;
	virtual ~Consumable() {}
	Consumable(string itemName, int itemHp=0,int itemMp=0) {
		name = itemName;
		hp = itemHp;mp = itemMp;
		type = Tpye_consumable;
		
	}
};

class QuestItem :public Equip {
public:
	virtual ~QuestItem() {}
	QuestItem() {
		name = "용의 눈물";
		type = Tpye_questItem;
	}
};