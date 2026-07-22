#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

int  main() {
	srand(time(NULL)); // 현재시간을 기준으로 랜덤 초기화

	// 치명타 (20% 확률)
	if (rand() % 100 <= 20)
	{
		cout << "치명타 발생\n";
	}
	else
	{
		cout << "일반 공격\n";
	}


	// 아이템 드랍
	int drop = rand() % 3; // rand() % a : 0 ~ a-1 범위에서 난수를 받는다.

	switch (drop) {
		case 0:
			cout << "포션 획득\n";
			break;
		case 1:
			cout << "검 획득\n";
			break;
		case 2:
			cout << "방패 획득\n";
			break;
		default:
			break;
	}

	return 0;
}
#endif