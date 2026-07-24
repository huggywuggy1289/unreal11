#include "Player.h"
#include "GameState.h"
#include "HandleStatAlloc.h"
#include "HandleTown.h"
#include "HandleDungeon.h"
#include <iostream>

using namespace std;

int main()
{
    // 초기값 선언

    Player player;
    player.name = "김전사";
    player.character = "전사";
    player.lv = 1;
    player.exp = 0;
    player.hp = 30;
    player.maxHp = 30;
    player.atk = 10;
    player.sp = 1;
    player.gold = 0;

    GameState state = GameState::STAT_ALLOC;
    
    while (state != GameState::EXIT) 
    {
        switch(state)
        {
        case GameState::STAT_ALLOC:
            state = HandleStatAlloc(&player);
            break;
        case GameState::TOWN:
            state = HandleTown(&player);
            break;
        case GameState::DUNGEON:
            state = HandleDungeon(&player);
            break;
        default:
            state = GameState::EXIT;
            break;
        }
    }
    return 0;
}

/*
[1차]
돌아간다 -> 집으로 돌아간다 -> 게임을 종료합니다.

[2차]
업그레이드 창으로 시작

생명력 올리면 -> 풀피 수치가 늘어남(maxhp, hp둘다) -> 돌아간다 -> 던전으로 간다 ->
-----------------드레곤 던전-----------------

고블린이(가) 나타났다!
고블린을(를) 물리쳤다! (받은 피해 : 8)
레벨 업! 현재 LV : 2 (SP +1)

오크이(가) 나타났다!
오크을(를) 물리쳤다! (받은 피해 : 24)
레벨 업! 현재 LV : 3 (SP +1)

던전을 클리어하고 마을로 돌아왔다. -> 마을을 살펴본다. -> "마을은 평화롭다. 그런데 어딘가 불안하다...." -> 주민에게 말을 건다 -> 주민이 말을 건넨다: "조심해서 다녀오게나." -> 던전으로 간다 ->
-----------------드레곤 던전-----------------

고블린이(가) 나타났다!
고블린을(를) 물리쳤다! (받은 피해 : 8)
레벨 업! 현재 LV : 4 (SP +1)

오크이(가) 나타났다!
오크에게 패배했다...
*/