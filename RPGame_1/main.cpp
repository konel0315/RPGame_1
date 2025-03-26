#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "GameProgress.h"

int main() {
    srand(time(0));
    Weapon* WeaponPtr_0 = new Weapon("대검",5);  // 무기
    Weapon* WeaponPtr_1 = new Weapon("단검",3);  // 무기

    Armor* ArmorPtr_0 = new Armor("금 갑옷",5); // 방어구
    Armor* ArmorPtr_1 = new Armor("금 투구",5); // 방어구
    Armor* ArmorPtr_2 = new Armor("금 신발",5); // 방어구
    Armor* ArmorPtr_3 = new Armor("금 방패",5); // 방어구

    Consumable* ConsumablePtr_0 = new Consumable("빨간 물약",5); 
    Consumable* ConsumablePtr_1 = new Consumable("파란 물약",0, 5);  // 소모품
    QuestItem* QuestItemPtr = new QuestItem(); //용의 눈물




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

    GameProgress gameProgress(PInven);  // GameProgress 객체 생성, Inventory 객체 전달

    gameProgress.GameRutin();

    delete WeaponPtr_0;  // Weapon 삭제
    delete WeaponPtr_1;  // Weapon 삭제

    delete ArmorPtr_0;   // Armor 삭제
    delete ArmorPtr_1;   // Armor 삭제
    delete ArmorPtr_2;   // Armor 삭제
    delete ArmorPtr_3;   // Armor 삭제

    delete ConsumablePtr_0;  // Consumable 삭제
    delete ConsumablePtr_1;  // Consumable 삭제

    delete QuestItemPtr;
    return 0;
}
