#pragma once
#include <iostream>
#include <string>

using namespace std;
class Item {
public:
	string name;
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
	Weapon() {
		name = "기본 검";
		element = 0;
		attack = 0;
	}
};

class Armor : public Equip {
public:

	virtual ~Armor() {}
	//무기 이름
	short element;//무기 속성
	int defense = 0;
	Armor() {
		name = "기본 갑옷";
		element = 0;
		defense = 0;
	}
};

class Consumable : public Item {
public:
	int hp = 0;
	int mp = 0;
	virtual ~Consumable() {}
	Consumable() {
		name = "물약";
		hp = 0;
		mp = 0;
	}
};

class QuestItem :Equip {

};
