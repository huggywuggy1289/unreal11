#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

enum RSP {
	RSP_ROCK,
	RSP_SCISSOR,
	RSP_PAPER,A
	RSP_END
};

int main() {
	srand(time(0));
	int player;

	cin >> player;

	while (true) {

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		if (player >= 3) {
			cout << "0~2까지만 입력가능" << endl;
			continue;
		}
		break;
	}

	int computer = rand() % RSP_END;

	if (player == computer) {
		cout << "비겼다" << endl;
	}
	else if (
		(player == RSP_ROCK && computer == RSP_SCISSOR) ||
		(player == RSP_SCISSOR && computer == RSP_PAPER) ||
		(player == RSP_PAPER && computer == RSP_ROCK)
		) {
		cout << "이겼다" << endl;
	}
	else {
		cout << "졌다" << endl;
	}
	return 0;
}
#endif