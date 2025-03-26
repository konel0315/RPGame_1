#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#include "Player.h"
using namespace std;
class Inventory {
public:
    vector<Item*> Exist;    // 존재하는 아이템 목록
    vector<Item*> PInventory;  // 플레이어 인벤토리
    Player player;  // Player 객체 추가

    Inventory();  // 생성자 선언
    void addItem(Item* item);     // addItem 함수 선언
    void exitItem(Item* item);    // exitItem 함수 선언
    void useItem(const string& itemname);
    void equipItem(const string& itemName);
    void displayInventory();
    void removeItem();
};
