#include <iostream>

using namespace std;

// 이 프레임 안의 num은 main 프레임의 number와 완전히 다른 메모리 주소에 쌓인다
/*
void increment(int num) {
	num = num + 1;
	cout << "함수 내 값 : " << num << endl;
	cout << "함수 내 주소값 : " << &num << endl;
}

int main() {

	int number = 0;
	increment(number);

	cout << "값 : " << number << endl;
	cout << "주소값 : " << & number << endl;
	return 0;
}
*/

// 스택은 이름이 아니라 "누가 호출했는지"에 따라 프레임을 쌓는 구조이다.

/*
 main에 선언된 그 number 변수를 가리키는 것이지만,
"값을 읽어서 복사해 넘겨주는" 방식이기때문에 그 값이 increment 함수 안으로 들어가는 순간, 
완전히 새로운 변수인 num에 복사되어 담기고 그때부터는
main의 number와는 아무 연결고리가 없다.
*/