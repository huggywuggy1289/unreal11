#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <stdio.h>
#include <type_traits>

using namespace std;

int main() {

	int a = 1;
	int b = 11;
	float c = 10.4f;

	// 값 타입만 비교
	bool is_same1 = is_same_v<decltype(a), decltype(b)>;
	bool is_same2 = is_same_v<decltype(a), decltype(c)>;
	bool is_same3 = is_same_v<decltype(b), decltype(c)>;

	bool b1 = (a == b); // 값이 같은지 묻는것 true
	bool b2 = (a != b); // 값이 같지 않는지 묻는것 true
	cout << b1 << endl;
	cout << b2 << endl;

	cout << (is_same1 ? "참" : "거짓") << endl;
	cout << (is_same2 ? "참" : "거짓") << endl;
	cout << (is_same3 ? "참" : "거짓") << endl;


	return 0;
}
#endif