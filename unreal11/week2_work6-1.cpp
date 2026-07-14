#include <iostream>
using namespace std;

int factorial(int n) {

	// 스택오버플로우 방지
	if (n <= 1) { // 1이면 재귀안함
		return 1;
	}
	return n * factorial(n - 1);
}
int main() {
	int a;

	cout << "insert number: " << endl;
	cin >> a;

	int b = factorial(a);

	cout << b << endl;

	return 0;
}