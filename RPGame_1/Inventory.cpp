#include "Inventory.h"
#include "Item.h"
#include "Player.h"

Inventory::Inventory() {}

void Inventory::useItem(const string& itemname) {
    for (int i = 0; i < PInventory.size(); i++) {
        if (PInventory[i]->name == itemname) {
            if (PInventory[i]->type == Tpye_consumable) {
                Consumable* consumable = dynamic_cast<Consumable*>(PInventory[i]);
                if (consumable) {
                    player.playerStatus.HP += consumable->hp;
                    player.playerStatus.MP += consumable->mp;
                    PInventory.erase(PInventory.begin() + i);
                    delete consumable;
                    break;
                }
            }
        }
    }
}

void Inventory::equipItem(const string& itemName) {
    for (int i = 0; i < PInventory.size(); i++) {
        if (PInventory[i]->name == itemName) {
            if (PInventory[i]->type == Tpye_weapon) {
                Weapon* weapon = dynamic_cast<Weapon*>(PInventory[i]);
                player.playerStatus.attack = weapon->attack;
                PInventory.erase(PInventory.begin() + i);
                delete weapon;
                break;
            }
            if (PInventory[i]->type == Tpye_armor) {
                Armor* armor = dynamic_cast<Armor*>(PInventory[i]);
                player.playerStatus.defense += armor->defense;
                PInventory.erase(PInventory.begin() + i);
                delete armor;
                break;
            }
        
        }
    }
}

void Inventory::displayInventory() {
    system("cls");
    for (int i = 0; i < PInventory.size(); i++) {
        cout << i << " : " << PInventory[i]->name << "\n";
    }
}

void Inventory::removeItem() {
    int i = -1;
    displayInventory();
    cin >> i;
    if (i >= 0 && i < PInventory.size()) {
        PInventory.erase(PInventory.begin() + i);
        displayInventory();
    }
    else cout << "제거할 아이템이 존재하지 않습니다.";
}

void Inventory::addItem(Item* item) {
    PInventory.push_back(item);
}

void Inventory::exitItem(Item* item) {
    Exist.push_back(item);
}
