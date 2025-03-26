#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "GameProgress.h"

int main() {
    srand(time(0));
    Weapon* WeaponPtr_0 = new Weapon("���",5);  // ����
    Weapon* WeaponPtr_1 = new Weapon("�ܰ�",3);  // ����

    Armor* ArmorPtr_0 = new Armor("�� ����",5); // ��
    Armor* ArmorPtr_1 = new Armor("�� ����",5); // ��
    Armor* ArmorPtr_2 = new Armor("�� �Ź�",5); // ��
    Armor* ArmorPtr_3 = new Armor("�� ����",5); // ��

    Consumable* ConsumablePtr_0 = new Consumable("���� ����",5); 
    Consumable* ConsumablePtr_1 = new Consumable("�Ķ� ����",0, 5);  // �Ҹ�ǰ
    QuestItem* QuestItemPtr = new QuestItem(); //���� ����




    Inventory PInven;
    PInven.exitItem(WeaponPtr_0);
    PInven.exitItem(WeaponPtr_1);

    PInven.exitItem(ArmorPtr_0);
    PInven.exitItem(ArmorPtr_1);
    PInven.exitItem(ArmorPtr_2);
    PInven.exitItem(ArmorPtr_3);

    PInven.exitItem(ConsumablePtr_0);
    PInven.exitItem(ConsumablePtr_1);
    PInven.exitItem(QuestItemPtr);

    GameProgress gameProgress(PInven);  // GameProgress ��ü ����, Inventory ��ü ����

    gameProgress.GameRutin();

    delete WeaponPtr_0;  // Weapon ����
    delete WeaponPtr_1;  // Weapon ����

    delete ArmorPtr_0;   // Armor ����
    delete ArmorPtr_1;   // Armor ����
    delete ArmorPtr_2;   // Armor ����
    delete ArmorPtr_3;   // Armor ����

    delete ConsumablePtr_0;  // Consumable ����
    delete ConsumablePtr_1;  // Consumable ����

    delete QuestItemPtr;
    return 0;
}
