#include "GameProgress.h"

int GameSwitch = 0;//0�� ������ 1�� ����
int QuestItemScore = 0;
GameProgress::GameProgress(Inventory& inventory) : inventory(inventory) {}

Item* GameProgress::serch() {
    int random_num = rand() % inventory.Exist.size();
    cout << "\n[ ���ο� ������ �߰�! ]\n";
    Item* newItem = nullptr;
    if (inventory.Exist[random_num]->type == Tpye_weapon) {
        Weapon* weapon = dynamic_cast<Weapon*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " ���ݷ� +" << weapon->attack << endl;
        newItem=new Weapon(*weapon);
    }
    else if (inventory.Exist[random_num]->type == Tpye_consumable) {
        Consumable* consumable = dynamic_cast<Consumable*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " Hp +" << consumable->hp << " Mp +" << consumable->mp << endl;
        newItem = new Consumable(*consumable);
    }
    else if (inventory.Exist[random_num]->type == Tpye_armor) {
        Armor* armor = dynamic_cast<Armor*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " ���� +" << armor->defense << endl;
        newItem = new Armor(*armor);
    }
    else if (inventory.Exist[random_num]->type == Tpye_questItem) {
        QuestItem* questItem = dynamic_cast<QuestItem*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " ����Ʈ ������ (��� ������): 10���� ���� �� ���� �¸� " << endl;
        QuestItemScore++;
        newItem = new QuestItem(*questItem);

    }
    return newItem;
}

void GameProgress::turn() {
    inventory.player.playerStatus.HP -= 3;
    inventory.player.playerStatus.MP -= 3;
}
void GameProgress::GameRutin() {
    while (GameSwitch==0) {
        inventory.player.showStatus();  // Player ���� ���
        Item* ImsiPtr = serch();  // GameProgress���� �������� �˻�
        inventory.addItem(ImsiPtr);

        cout << "\n[ �ൿ�� �����ϼ��� ]\n";
        cout << "1. ������ ���\n";
        cout << "2. ������ ����\n";
        cout << "3. �κ��丮 Ȯ��\n";
        int num = 0;
        cin >> num;

        if (num == 1) {
            
            if (ImsiPtr->type == Tpye_consumable) {
                Consumable* consumable = dynamic_cast<Consumable*>(ImsiPtr);
                system("cls");
                cout << "\n[  ��� ���� ]\n";
                cout << "-" << ImsiPtr->name << " ��� �Ϸ� " << "( Hp +" << consumable->hp << ")" << "( Mp +" << consumable->mp << ")" << endl;
                inventory.useItem(ImsiPtr->name);
            }
            if (ImsiPtr->type == Tpye_questItem) {
                QuestItem* questItem = dynamic_cast<QuestItem*>(ImsiPtr);
                system("cls");
                cout << "\n[ ��� ���� ]\n";
                cout << "-" << ImsiPtr->name << " ��� �Ϸ� " << QuestItemScore <<"�� ����Ͽ����ϴ�" << endl;
                inventory.equipItem(ImsiPtr->name);
            }
        }
        else if (num == 2) {
        if (ImsiPtr->type == Tpye_weapon) {
            Weapon* weapon = dynamic_cast<Weapon*>(ImsiPtr);
            system("cls");
            cout << "\n[ ���� ���� ]\n";
                cout << "-" << ImsiPtr->name << " ���� �Ϸ� " << "( ���ݷ� +" << weapon->attack << ")" << endl;
                inventory.equipItem(ImsiPtr->name);
            }
        if (ImsiPtr->type == Tpye_armor) {
                
                Armor* armor = dynamic_cast<Armor*>(ImsiPtr);
                system("cls");
                cout << "\n[ ���� ���� ]\n";
                cout << "-" << ImsiPtr->name << " ���� �Ϸ� " << "( ���� +" << armor->defense << ")" << endl;
                inventory.equipItem(ImsiPtr->name);
            }
            
        }
        else if (num == 3) {
            inventory.displayInventory();
        }

        turn();  // �� ����
        end();
    }
}
void GameProgress::end() {
    if (inventory.player.playerStatus.HP <= 0) { GameSwitch = 1; cout << "�÷��̾ ����Ͽ����ϴ�."; }
    if (QuestItemScore == 10) { cout << "�÷��̾ �¸��Ͽ����ϴ�."; }
}
