#pragma once
#include "Player.h"

// 입력값 검증 cin.fail()
int GetValidChoice(int minVal, int maxVal);


// 플레이어 상태 상단에 출력하기
void PrintPlayerStatus(Player* player);