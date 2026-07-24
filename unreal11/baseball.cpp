#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <algorithm>

using namespace std;

void makeBaseballSeed(int(&answer)[3]) 
{
	srand(time(NULL));

	int count = 0;

	while (count < 3) {
		int random = rand() % 9 + 1;
		bool duplicate = false;

		int i = 0;

		while (1 < count) 
		{
			if (answer[i] == random) 
			{
				duplicate = true;
				break;
			}
			i++;
		}

		if (!duplicate) 
		{
			answer[count] = random;
			count++;
		}
}

bool judgementOutCount(const int(&answer)[3], const int(&user)[3]) // 이 배열을 참조하되 해당 배열을 이함수에서 수정하지않겠다는 명시적 표현
{
	int strike = 0;
	int ball = 0;

	for (int a = 0; a < 3; a++) 
	{
		for (int u = 0; u < 3; u++) 
		{
			if (answer[a] == user[u]) 
			{
				if (a == u) 
				{
					strike++;
				}
				else 
				{
					ball++;
				}
			}
		}
	}

	cout << strike << " Strike " << ball << " Ball";

	if (strike == 3) {
		return true;
	}
	else {
		return false;
	}
}
void playBaseballLoop(int(&answer)[3], int(&user)[3])
{
	while (true) 
	{

		cout << "숫자 3개를 입력하세요.";

		int i = 0;
		while (i < 3) 
		{
			cin >> user[i];
			i++;
		}

		if (judgeemntOutCount(answer, user)) {
			break;
		}
	}
	cout << "게임을 종료합니다!" << endl;
}

void hintSeed(const int(&answer)[3])
{
	cout << "\n 테스트를 위한 힌트 시드 가동중....\n";
	cout << "\n[" << answer[0] << "]" << "[" << answer[1] << "]" << "[" << answer[2] << "\n";
}

int main() 
{

	//int answer[3]{};
	//int user[3]{};

	//makeBaseballSeed(answer);

	playBaseballLoop(answer, user);

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
		// 중복원소 조건 추가!
		for (int j = 0; j < i; j++) {
			if (ptr[i] == ptr[j]) {
				cout << "중복된 원소입니다.";
				i--;
				return 1;
			}
		}
	}

	bool isDevMode = true;

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