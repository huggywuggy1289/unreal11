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
    cout << "게임을 종료합니다." << endl;
    return 0;
}
