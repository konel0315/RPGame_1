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
	//���� �̸�
	short element;//���� �Ӽ�
	Weapon() {
		name = "�⺻ ��";
		element = 0;
	}
};

class Armor :Equip {

};

class Consumable : public Item {
public:

	virtual ~Consumable() {}
	Consumable() {
		name = "����";
	}
};

class QuestItem :Equip {

};
