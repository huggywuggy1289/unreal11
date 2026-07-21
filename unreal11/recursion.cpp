#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <string>

using namespace std;

long long factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}
int main() {
	int number;
	cin >> number;
	if (cin.fail()) {
		cout << "올바르지 않은 타입입니다..;";
		return 1;
	}

	cout << number << "!의 값은 " << factorial(number) << endl;
}
#endif