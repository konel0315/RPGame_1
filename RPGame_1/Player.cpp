#include "Player.h"

void Player::status(string name, int hp, int mp, int attack, int defense) {
    playerStatus.name = name;
    playerStatus.HP = hp;
    playerStatus.MP = mp;
    playerStatus.attack = attack;
    playerStatus.defense = defense;
}

void Player::showStatus() {
    cout << "\n[ 플레이어 스탯 ]\n" << "이름 : " << playerStatus.name
        << "\nHP : " << playerStatus.HP << ", MP : " << playerStatus.MP
        << "\n공격력 : " << playerStatus.attack << " 방어력 : " << playerStatus.defense << endl;
}
