#include <iostream>
using namespace std;

enum RSP {
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,
	RSP_END
};

int main() {
	srand(time(0));

	int player;
	cout << "0: 바위, 1: 가위, 2: 보 중 선택: ";
	cin >> player;

	int computer = rand() % RSP_END;

	cout << "컴퓨터: " << computer << endl;

	// 예외처리
	if (player != 0 || 1 || 2) {
		cout << "적절한 정수가 아닙니다." << endl;
		return 1;
	}

	if (player == computer) {
		cout << "비겼다!" << endl;
	}
	else if ( // 플레이어가 이긴 경우
		// 바위 > 가위
		// 가위 > 보
		// 보 > 바위
		(player == RSP_ROCK && computer == RSP_SCISSOR) ||
		(player == RSP_SCISSOR && computer == RSP_PAPER) ||
		(player == RSP_PAPER && computer == RSP_ROCK)
		) 
	{
		cout << "이겼다!" << endl;
	}
	else { // 플레이어가 진 경우
		cout << "졌다!" << endl;
	}
	return 0;
}