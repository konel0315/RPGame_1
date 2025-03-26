#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#include "Player.h"
using namespace std;
class Inventory {
public:
    vector<Item*> Exist;    // �����ϴ� ������ ���
    vector<Item*> PInventory;  // �÷��̾� �κ��丮
    Player player;  // Player ��ü �߰�

    Inventory();  // ������ ����
    void addItem(Item* item);     // addItem �Լ� ����
    void exitItem(Item* item);    // exitItem �Լ� ����
    void useItem(const string& itemname);
    void equipItem(const string& itemName);
    void displayInventory();
    void removeItem();
};
