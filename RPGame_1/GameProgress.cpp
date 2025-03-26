#include "GameProgress.h"

int GameSwitch = 0;//0은 진행중 1은 엔딩
int QuestItemScore = 0;
GameProgress::GameProgress(Inventory& inventory) : inventory(inventory) {}

Item* GameProgress::serch() {
    int random_num = rand() % inventory.Exist.size();
    cout << "\n[ 새로운 아이템 발견! ]\n";
    Item* newItem = nullptr;
    if (inventory.Exist[random_num]->type == Tpye_weapon) {
        Weapon* weapon = dynamic_cast<Weapon*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " 공격력 +" << weapon->attack << endl;
        newItem=new Weapon(*weapon);
    }
    else if (inventory.Exist[random_num]->type == Tpye_consumable) {
        Consumable* consumable = dynamic_cast<Consumable*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " Hp +" << consumable->hp << " Mp +" << consumable->mp << endl;
        newItem = new Consumable(*consumable);
    }
    else if (inventory.Exist[random_num]->type == Tpye_armor) {
        Armor* armor = dynamic_cast<Armor*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " 방어력 +" << armor->defense << endl;
        newItem = new Armor(*armor);
    }
    else if (inventory.Exist[random_num]->type == Tpye_questItem) {
        QuestItem* questItem = dynamic_cast<QuestItem*>(inventory.Exist[random_num]);
        cout << "-" << inventory.Exist[random_num]->name << " 퀘스트 아이템 (사용 아이템): 10개를 모을 시 게임 승리 " << endl;
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
        inventory.player.showStatus();  // Player 상태 출력
        Item* ImsiPtr = serch();  // GameProgress에서 아이템을 검색
        inventory.addItem(ImsiPtr);

        cout << "\n[ 행동을 선택하세요 ]\n";
        cout << "1. 아이템 사용\n";
        cout << "2. 아이템 장착\n";
        cout << "3. 인벤토리 확인\n";
        int num = 0;
        cin >> num;

        if (num == 1) {
            
            if (ImsiPtr->type == Tpye_consumable) {
                Consumable* consumable = dynamic_cast<Consumable*>(ImsiPtr);
                system("cls");
                cout << "\n[  사용 성공 ]\n";
                cout << "-" << ImsiPtr->name << " 사용 완료 " << "( Hp +" << consumable->hp << ")" << "( Mp +" << consumable->mp << ")" << endl;
                inventory.useItem(ImsiPtr->name);
            }
            if (ImsiPtr->type == Tpye_questItem) {
                QuestItem* questItem = dynamic_cast<QuestItem*>(ImsiPtr);
                system("cls");
                cout << "\n[ 사용 성공 ]\n";
                cout << "-" << ImsiPtr->name << " 사용 완료 " << QuestItemScore <<"개 사용하였습니다" << endl;
                inventory.equipItem(ImsiPtr->name);
            }
        }
        else if (num == 2) {
        if (ImsiPtr->type == Tpye_weapon) {
            Weapon* weapon = dynamic_cast<Weapon*>(ImsiPtr);
            system("cls");
            cout << "\n[ 장착 성공 ]\n";
                cout << "-" << ImsiPtr->name << " 장착 완료 " << "( 공격력 +" << weapon->attack << ")" << endl;
                inventory.equipItem(ImsiPtr->name);
            }
        if (ImsiPtr->type == Tpye_armor) {
                
                Armor* armor = dynamic_cast<Armor*>(ImsiPtr);
                system("cls");
                cout << "\n[ 장착 성공 ]\n";
                cout << "-" << ImsiPtr->name << " 장착 완료 " << "( 방어력 +" << armor->defense << ")" << endl;
                inventory.equipItem(ImsiPtr->name);
            }
            
        }
        else if (num == 3) {
            inventory.displayInventory();
        }

        turn();  // 턴 진행
        end();
    }
}
void GameProgress::end() {
    if (inventory.player.playerStatus.HP <= 0) { GameSwitch = 1; cout << "플레이어가 사망하였습니다."; }
    if (QuestItemScore == 10) { cout << "플레이어가 승리하였습니다."; }
}
