#include <iostream>
#include "Player.h"

using namespace std;

// 최대체력증가(생명력도 비례하여 증가)
void IncreaseMaxHp(Player* player) {

	if (player->sp <= 0) {
		cout << "sp가 부족합니다.\n";
		return;
	}
	player->sp -= 1;

	player->maxHp += 15;
	player->hp += 15;

}

// 공격력 증가
void IncreaseAtk(Player* player) {
	if (player->sp <= 0) {
		cout << "sp가 부족합니다.\n";
		return;
	}
	player->sp -= 1;
	
	player->atk +=  15;
}