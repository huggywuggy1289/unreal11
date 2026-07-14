#include <iostream>
#include <string>

using namespace std;

int main() {
	float pie = 3.14;
	int r;

	cout << "반지름을 입력하세요" << endl;
	cin >> r;

	int width = r * r * pie;

	cout << "원의 넓이는 " << width << "입니다." << endl;

	return 0;
}