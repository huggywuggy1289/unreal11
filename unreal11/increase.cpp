#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	/*
	증감연산자
	*/

	int HP = 10;

	// if 슬라임이 공격력 1인데 player에게 데미지를 준경우
	HP--; // HP = HP - 1; 와 같다.

	// if player가 회복약을 먹은경우
	HP++; // HP = HP + 1; 와 같다.

	// 전위증가는 대입즉시 반영, 후위증가는 대입이후에 반영
	int num = 0;
	cout << "전위 연산자 증가시 : " << ++num << endl; //1
	cout << "후위 연산자 증가시 : " << num++ << endl; //1 (대입한 와중에는 증가한 값안뜸)
	cout << "후위연산자 증가동시에 사용 : " << num++ << endl; // 2
	cout << "후위연산자 사용 : " << num << endl; // 3

	int number = 45;
	number *= 2; // 50

	int Gold = 500;
	Gold = Gold + 500; // 1000
	Gold += 500; // 1500

	return 0;
}
#endif