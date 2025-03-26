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
	int attack = 0;
	Weapon() {
		name = "�⺻ ��";
		element = 0;
		attack = 0;
	}
};

class Armor : public Equip {
public:

	virtual ~Armor() {}
	//���� �̸�
	short element;//���� �Ӽ�
	int defense = 0;
	Armor() {
		name = "�⺻ ����";
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
		name = "����";
		hp = 0;
		mp = 0;
	}
};

class QuestItem :Equip {

};
