#pragma once
#include <string>
#include <iostream>
using namespace std;
class Player {
public:
    struct PlayerStatus {
        std::string name = "±èÃ¶¼ö";
        int HP = 100;
        int MP = 100;
        int attack = 10;
        int defense = 5;
    };

    PlayerStatus playerStatus;

    void status(std::string name, int hp, int mp, int attack, int defense);
    void showStatus();
};
