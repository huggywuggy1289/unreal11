#include <iostream>
using namespace std;

enum RSP {
	RSP_ROCK, // 0
	RSP_SCISSOR, // 1
	RSP_PAPER, // 2
	RSP_END // 3
};

int main() {
	srand(time(0));
	int player;

	while (true) {

		cout << "0: 바위, 1: 가위, 2: 보 중 선택: ";
		cin >> player;

		if (cin.fail()) {
			cin.clear(); // 입력값 지우기
			cin.ignore(10000, '\n'); // 입력버퍼가 지워짐
			cout << "숫자를 입력해주세요." << endl;
			continue;
		}

		if (player < RSP_ROCK || player >= RSP_END) {
			cout << "0, 1, 2 중 하나만 입력해주세요." << endl;
			continue;
		}
		break;
	}
	int computer = rand() % RSP_END;
	cout << "컴퓨터: " << computer << endl;

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