#include "Utils.h"
#include <iostream>

int GetValidChoice(int minVal, int maxVal) {

	int choice;

	while (true) 
	{
		cin >> choice;
		if (cin.fail() || minVal > choice || maxVal < choice) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
	}
	return choice;
}

void PrintPlayerStatus(Player* player) {
	cout << "----------------[스워드 월드]----------------\n";
	cout << "이름 : " << player->name << "\t\t클래스 : " << player->character << "\n";
	cout << "LV : " << player->lv << "\t\t\tEXP : " << player->exp << "\n";
	cout << "HP : " << player->hp << "/" << player->maxHp
		<< "\t\t골드 : " << player->gold << "\n";
	cout << "공격력 : " << player->atk << "\n";
	cout << "-----------------------------------------------\n";
}