#include <iostream>
using namespace std;

int factorial(int n) {

	int k = 1;
	for (int i = n; i > 0; i--) {
		k *= i;
	}
	return k;
}

int main() {

	int a;

	cout << "insert number: " << endl;
	cin >> a;

	int b = factorial(a);

	cout << b << endl;

	return 0;
}