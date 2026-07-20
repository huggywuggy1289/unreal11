#include <iostream>
#include <string>

using namespace std;

int main() {

	// 이전 경험치
	int befLv;
	cin >> befLv;

	// 얻은 경험치
	int getLv;
	cin >> getLv;

	int meNow = befLv + getLv;

	cout << "현재 경험치 : " << meNow << endl;
	bool isLevelUp = false;

	if (meNow >= 1000) {
		isLevelUp = true;
		cout << "레벨업 여부 : " << isLevelUp << endl;
	}
	else {
		cout << "레벨업 여부 : " << isLevelUp << endl;
	}

	return 0;
}