#pragma once
#include "Inventory.h"
using namespace std;
class GameProgress {
public:
    GameProgress(Inventory& inventory);  // Inventory 객체를 받아옴

    Item* serch();  // 아이템 탐색 메서드
    void turn();    // 턴 진행 메서드
    void GameRutin();
    void end();
private:
    Inventory& inventory;  // 게임 진행에 필요한 Inventory 참조
};