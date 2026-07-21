//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//
//	int num;
//	cin >> num;
//	if (cin.fail() || num < 0) {
//		cout << "잘못된 타입입니다." << endl;
//		return 0;
//	}
//
//	int timeShare = num / 3600;
//	int timeReminder = num % 3600;
//
//	int hour = timeShare;
//	int minute = timeReminder / 60;
//	int second = timeReminder % 60;
//	cout << hour << "시간 " << minute << "분 " << second << "초" << endl;
//
//	return 0;
//}