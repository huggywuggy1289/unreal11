#include <iostream>
#include <stdio.h>

using namespace std;

int main() {


	// 문제1

	int money;
	int a = 1000;
	int b = 500;
	int c = 100;

	cout << "거스름돈을 입력하세요 : " << endl;
	cin >> money;

	// (3250 -3000 - 0) / 100 = 2
	// (3750 -3000 -500) / 100 = 2
	int d = money / a; // 3250에서 1000원을 나누면 1000짜리 3장 나옴
	int e = (money - (d * a)) / b; // 전체 총액에서 1000*3장을 뺌 750에 500나눔 = 0나옴
	int f = (money - (d * a) - (e * b)) / c;

	cout << "천원 지폐 : " << d << "장" << endl;
	cout << "오백원 동전 : " << e << "개" << endl;
	cout << "백원 동전 : " << f << "개" << endl;

	// 문제2

	int age = 20;
	cout << "현재 나이: " << age << "살" << endl;
	
	age++;
	cout << "내년 나이: " << age << "살" << endl;

	int after10 = age + 10;
	cout << "10년 뒤 나이는: " << after10 << "살" << endl;

}