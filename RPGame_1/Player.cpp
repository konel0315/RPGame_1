#include "Player.h"

void Player::status(string name, int hp, int mp, int attack, int defense) {
    playerStatus.name = name;
    playerStatus.HP = hp;
    playerStatus.MP = mp;
    playerStatus.attack = attack;
    playerStatus.defense = defense;
}

void Player::showStatus() {
    cout << "\n[ �÷��̾� ���� ]\n" << "�̸� : " << playerStatus.name
        << "\nHP : " << playerStatus.HP << ", MP : " << playerStatus.MP
        << "\n���ݷ� : " << playerStatus.attack << " ���� : " << playerStatus.defense << endl;
}
