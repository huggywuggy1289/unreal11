//#include <iostream>
//#include <stdio.h>
//#include <vector>
//using namespace std;
//
//int main() {
//
//	int money = 3834;
//	vector<int> coins = { 500, 100 };
//	int total_count = 0;
//
//	for (int coin : coins) {
//		int count = money / coin; // 3800 / 500 = 7 -> 300 / 100 = 3
//		money %= coin; // 3800 % 500 = 300 -> 300 % 100 = 0
//		total_count += count; // 7 -> 7+3 = 10
//
//		cout << coin << "원 동전 개수는 " << count << "개 입니다." << endl;
//	}
//
//	while (money > 0) {
//		cout << "나머지 금액은 동전으로 꺼낼 수 없습니다." << endl;
//		break;
//	}
//
//	cout << "총 동전의 개수는 " << total_count << "개 입니다." << endl;
//
//	return 0;
//}