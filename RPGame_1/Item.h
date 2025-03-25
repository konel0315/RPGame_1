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
	Weapon() {
		name = "기본 검";
		element = 0;
	}
};

class Armor :Equip {

};

class Consumable : public Item {
public:

	virtual ~Consumable() {}
	Consumable() {
		name = "물약";
	}
};

class QuestItem :Equip {

};
