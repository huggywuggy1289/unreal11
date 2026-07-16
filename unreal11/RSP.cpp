//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//using namespace std;
//
//enum RSP {
//	RSP_ROCK, // 0
//	RSP_SCISSOR, // 1
//	RSP_PAPER, // 2
//	RSP_END // 3
//};
//
//int main() {
//	srand(time(0)); // "s"는 seed라는 뜻으로 인자로 주어진 수치에 따라 rand() 값을 변경
//	int player;
//
//	while (true) {
//
//		cout << "0: 바위, 1: 가위, 2: 보 중 선택: ";
//		cin >> player;
//
//		// 조건1
//		if (cin.fail()) {
//			cin.clear(); // 입력값 지우기
//			cin.ignore(10000, '\n'); // 둘중 먼저 실행되는 조건에서 입력버퍼가 지워짐. 예로 사용자가 23223입력하고 1만 설정했으면 1글자만 지워지므로 최대한 많은 문자열을 비우도록 임의로 설정한 값이다.
//			cout << "문자열이나 특수기호는 사용하실 수 없습니다." << endl;
//			continue;
//		}
//
//		// 조건2
//		if (player < RSP_ROCK || player >= RSP_END) {
//			cout << "0, 1, 2 중 하나만 입력해주세요." << endl;
//			continue;
//		}
//		break; // 반복문 탈출
//	}
//
//	// rand() 함수가 반환하는 값은 0~32767 사이의 값
//	// rand() 함수는 srand함수에 의존적
//
//	/*
//	srand 함수를 호출하지 않고, rand() 호출한다면 srand(1)로 설정된 상태
//	*/
//	int computer = rand() % RSP_END;
//	cout << "컴퓨터: " << computer << endl;
//
//	if (player == computer) {
//		cout << "비겼다!" << endl;
//	}
//	else if ( // 플레이어가 이긴 경우
//		// 바위 > 가위
//		// 가위 > 보
//		// 보 > 바위
//		(player == RSP_ROCK && computer == RSP_SCISSOR) ||
//		(player == RSP_SCISSOR && computer == RSP_PAPER) ||
//		(player == RSP_PAPER && computer == RSP_ROCK)
//		)
//	{
//		cout << "이겼다!" << endl;
//	}
//	else { // 플레이어가 진 경우
//		cout << "졌다!" << endl;
//	}
//	return 0;
//}