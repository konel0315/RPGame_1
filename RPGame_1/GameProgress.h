#pragma once
#include "Inventory.h"
using namespace std;
class GameProgress {
public:
    GameProgress(Inventory& inventory);  // Inventory ��ü�� �޾ƿ�

    Item* serch();  // ������ Ž�� �޼���
    void turn();    // �� ���� �޼���
    void GameRutin();
    void end();
private:
    Inventory& inventory;  // ���� ���࿡ �ʿ��� Inventory ����
};