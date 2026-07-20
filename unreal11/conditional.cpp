#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	// is-else
	int myLevel = 15;

	if (myLevel >= 10) {
		cout << "전직퀘스트 도착" << endl;
	}
	else if(myLevel > 20){
		cout << "그랜드 마스터 달성" << endl;
	}
	else {
		cout << "레벨이 부족합니다. 사냥터로 가세요" << endl;
	}

	cout << "----------------------------------------------------" << endl;

	// (2)
	int ddayNumber;
	cout << "1부터 7까지 입력받아서 요일을 출력해보세요 : " << endl;
	cin >> ddayNumber;

	switch (ddayNumber) {
		case 1:
			cout << "입력 : " << ddayNumber << endl;
			cout << "출력 : 월요일";
			break; // 브레이크 없으면 입력한 숫자보다 큰값들에 해당하는 문자열까지 전부 출력됨.
		case 2:
			cout << "입력 : " << ddayNumber << endl;
			cout << "출력 : 화요일";
			break;
		case 3 :
			cout << "입력 : " << ddayNumber << endl;
			cout << "출력 : 수요일";
			break;
		case 4:
			cout << "입력 : " << ddayNumber << endl;
			cout << "출력 : 목요일";
			break;
		case 5:
			cout << "입력 : " << ddayNumber << endl;
			cout << "출력 : 금요일";
			break;
		case 6:
			cout << "입력 : " << ddayNumber << endl;
			cout << "출력 : 토요일";
			break;
		case 7:
			cout << "입력 : " << ddayNumber << endl;
			cout << "출력 : 일요일";
			break;
		default:
			cout << "제발 입력하라는 숫자만 입력해라";
			break;
	}

	return 0;
}

// 10시 10분 -> 9시 25분 hour --; minute += 15;