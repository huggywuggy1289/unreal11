#include <iostream>
#include <string>

using namespace std;


void addHundred(int scoreNum) {
	cout << "복사된 값 : " << scoreNum + 100 << endl;
}

void reset(int &lifeNum) { // 2. life의 주소지를 받아와
	int num = 0; // 3. 주소지내 값을 0으로 전환시켜서
	lifeNum = num; // lifeNum에 재할당
}

void doubleValue(int* p) { // 2. p는 money의 주소지를 가리키고
	// 3. *p는 money 변수안에 든 값을 가리킨다. 따라서
	if (p == nullptr) {
		return;
	}
	*p = (*p) * 2; // 4. 이렇게 2배의 값을 해준다.
	cout << "money변수의 주소지 : " << p << endl;
}

int main() {
	
	// 문제 1 : 정수 한개를 받아서 100을 더하는 방식을 call by value방식으로 구현하시오.
	int score = 50;
	addHundred(score);
	cout << "원본 값 : " << score << endl;

	// 문제 2 : 정수 1개를 받아서 0으로 만드는 함수 reset을 call by reference방식으로 구현하시오.
	int life = 7;
	reset(life); // 1. 니가 life를 넣으면
	cout << "참조된 값 : " << life << endl;

	// 문제 3 : 정수 1개를 받아서 값을 2배로 만드는 함수 doubleValue를 call by pointer방식으로 구현하시오.
	int money = 30;
	doubleValue(&money); // 1. 니가 money변수의 주소값을 전달하면
	cout << "money 변수의 실제 값 : " << money << endl;


	return 0;
}

/*
복사된 값 : 150
원본 값 : 50
참조된 값 : 0
money변수의 주소지 : 0000003B0874FA24
money 변수의 실제 값 : 60
*/
