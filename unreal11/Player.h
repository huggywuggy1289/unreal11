#pragma once
#include <string>

using namespace std;

struct Player {

	string name = "";
	string character = "";
	int lv = 0;
	int exp = 0;
	int hp = 0;
	int maxHp = 0;
	int atk = 0; // 소숫점 반올림으로 정수를 만들것이니 계산 과정에서만 float처리하면 됨.
	int sp = 0;
	int gold = 0;
};

struct Item {
	string name;
	int bonus;
};

void IncreaseMaxHp(Player* player);
void IncreaseAtk(Player* player);