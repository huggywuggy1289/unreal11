#include <iostream>
#include <string>

using namespace std;

int main() {

	int num;
	//int hour;
	//int minute;
	//int second;
	cin >> num;
	if (cin.fail()) {
		cout << "잘못된 타입입니다." << endl;
		return 0;
	}

	// 1시간 = 60분 = 3600초 3665 / 3600 = 1 3665 % 3600 = 65

	int hour = num / 3600; // 65초가 나머지
	int minute = (num % 3600) / 60; // 5가 나머지
	int second = (num % 3600) % 60; // 분단위에서 60을 나눈 나머지

	cout << hour << "시간 " << minute << "분 " << second << "초" << endl;

	return 0;
}