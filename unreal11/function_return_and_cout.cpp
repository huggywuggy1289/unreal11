#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <string>

using namespace std;

// 이건 greet()도 가능하고 greet(name)도 가능하다.
// default argument = 아무것도 작성하지않으면 기본값으로 전달해라.
void greet(string name = "guest") {
	cout << "hello, " << name << "!\n";
}

void print(string str){
	cout << str << "입니다." << "\n";
}

void test() {
	cout << "테스트 중입니다." << endl;
}

string GetTestString(int num) // 매개변수인 숫자를
{
	string str = ""; // 선언한 문자열을
	switch (num) {
		case 1 : // 조건으로 달고
			str = "one"; // 결괏값으로 내보내고
			break;
		case 2:
			str = "two";
			break;
		case 3:
			str = "three";
			break;
		case 4:
			str = "four";
			break;
		case 5:
			str = "five";
			break;
		default:
			str = "올바르지않은 숫자입니다.";
			break;
	}
	cout << str << endl; // 눈에 보이게 해주겠다는 의미
	return str; // 단순 str을 반환하겠다는 사실을 적시
}
int main() {

	string str;
	cin >> str;

	int number;
	cin >> number;
	if (cin.fail()) {
		cout << "올바르지않은 타입입니다." << endl;
		return 1;
	}

	print(str);
	GetTestString(number); // 출력안됨. 반환받은 값을 모니터 화면에 출력해 달라는 명령(cout)이 없기 때문
	//cout << GetTestString(number) << endl; // 출력됨. 왜?

	return 0;
}
#endif