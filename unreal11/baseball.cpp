#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{

	int answer[] = { 3,7,1 };
	int size = sizeof(answer) / sizeof(answer[0]);

	// 입력받을 숫자를 담을 배열L
	int* ptr = new int[size];

	cout << "숫자를 입력하세요 : " << endl;

	bool inputError = false;
	// 지정된 배열만큼 입력받기
	for (int i = 0; i < size; i++)
	{

		// 입력받을 숫자
		cin >> ptr[i];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "유효한 타입이 아닙니다." << endl;
			inputError = true;
			break;
		}

		if (inputError) {
			continue;
		}
	}

	int strike = 0;
	int ball = 0;

	for (int i = 0; i < size; i++) 
	{

		// ptr[i]의 숫자와 answer[i]의 숫자의 위치도 같으면
		if (ptr[i] == answer[i]) {
			strike++;
		}
		// ptr에 있는 숫자와 answer의 숫자도 같지만 위치가 다르면
		// anyof써야할거같은데 어케쓰노
		// stackoverflow 왈 : any_of(answer, answer + size, [&](int a){return a==ptr[i]})
		else if (any_of(answer, answer + size, [&](int a) {return a == ptr[i]; })) {
			ball++;
		}
	}

	cout << strike << " Strike " << ball << " Ball";

	delete[] ptr;
	ptr = nullptr;
	return 0;

}
#endif
/*
int x = 3;
std::vector values = {1, 2, 3};
if (std::any_of(values.begin(), values.end(), [x](int y) { return x == y; }))
// ...
*/