#include "Player.h"
#include "Dragon.h"
#include "GameState.h"
#include <iostream>

using namespace std;

bool FightMonster(Player* player, Dragon dragon) {
    cout << "\n" << dragon.name << "이(가) 나타났다!\n";

    int turnsToKill = (dragon.hp + player->atk - 1) / player->atk; // 올림 나눗셈
    int damageTaken = turnsToKill * dragon.atk;

    if (player->hp - damageTaken > 0) {
        player->hp -= damageTaken;
        cout << dragon.name << "을(를) 물리쳤다! (받은 피해 : " << damageTaken << ")\n";

        // 승리 보상
        player->exp += dragon.exp;
        player->gold += dragon.gold;
        player->lv += 1;
        player->sp += 1;
        cout << "레벨 업! 현재 LV : " << player->lv << " (SP +1)\n";

        return true;
    }
    else {
        player->hp = 0;
        cout << dragon.name << "에게 패배했다...\n";
        return false;
    }
}

GameState HandleDungeon(Player* player) {
    cout << "-----------------드레곤 던전-----------------" << endl;

    Dragon dragon1 = { "고블린", 20, 4, 15, 10 };
    Dragon dragon2 = { "오크", 35, 6, 25, 20 };

    if (!FightMonster(player, dragon1)) {
        return GameState::EXIT;
    }

    if (!FightMonster(player, dragon2)) {
        return GameState::EXIT;
    }

    cout << "\n던전을 클리어하고 마을로 돌아왔다.\n";
    return GameState::TOWN;
}
