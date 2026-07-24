#include "Player.h"
#include "Dragon.h"
#include "Utils.h"
#include "GameState.h"
#include <iostream>

using namespace std;

GameState HandleStatAlloc(Player* player)
{
	cout << "-----------------업그레이드 창-----------------" << endl;
	PrintPlayerStatus(player);

	// 현재 클래스 출력
	cout << "남은 SP : " << player->sp << "\n";
	cout << "생명력(maxHp) 수치 : " << player->maxHp << "\n";
	cout << "공격력(atk) 수치 : " << player->atk << "\n";

	// 메뉴 출력
	cout << "\n[1] 생명력을 올린다\n";
	cout << "[2] 공격력을 올린다\n";
	cout << "[3] 돌아간다\n";

	cout << "무엇을 하시겠습니까? : ";

	int choice = GetValidChoice(1, 3);

	switch (choice)
	{
	case 1:
		IncreaseMaxHp(player);
		return GameState::STAT_ALLOC;
	case 2:
		IncreaseAtk(player);
		return GameState::STAT_ALLOC;
	case 3:
		return GameState::TOWN;
	default:
		return GameState::STAT_ALLOC;
	}

}