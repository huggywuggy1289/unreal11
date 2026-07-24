#include "Player.h"
#include "Utils.h"
#include "GameState.h"
#include <iostream>

using namespace std;



GameState HandleTown(Player* player) {

	cout << "-----------------스워드 마을-----------------" << endl;
	PrintPlayerStatus(player);

	cout << "\n[1] 마을을 살펴본다\n";
	cout << "[2] 주민에게 말을 건다\n";
	cout << "[3] 던전으로 간다\n";
	cout << "[4] 집으로 돌아간다\n\n";

	cout << "무엇을 하시겠습니까? : ";

	int choice = GetValidChoice(1, 4); // Utils.h

	switch (choice)
	{
	case 1:
		cout << "\n마을은 평화롭다\n 그런데 어딘가 불안하다....";
		return GameState::TOWN;
	case 2:
		cout << "\n주민이 말을 건넨다: \"조심해서 다녀오게나.\"\n";
		return GameState::TOWN;
	case 3:
		return GameState::DUNGEON;
	case 4:
		cout << "\n게임을 종료합니다.\n";
		return GameState::EXIT;
	default:
		return GameState::TOWN;
	}
}