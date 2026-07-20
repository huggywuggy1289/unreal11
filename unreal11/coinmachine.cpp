#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {

	int money = 23403;
	vector<int> coins = { 500, 100 };
	int total_count = 0;

	for (int coin : coins) {
		int count = money / coin;
		money %= coin;
		total_count += count;

		cout << coin << "원 동전 개수는 " << count << "개 입니다." << endl;
	}

	while (money > 0) {
		cout << "나머지 금액은 동전으로 꺼낼 수 없습니다." << endl;
		break;
	}

	cout << "총 동전의 개수는 " << total_count << "개 입니다." << endl;

	return 0;
}