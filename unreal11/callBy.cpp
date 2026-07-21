#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <string>

using namespace std;


// a,b값 순서교체
void swapByValue(int a, int b) {
	int temp = a; // temp 변수에 a값 복사
	a = b; // a에 b의 값복사
	b = temp; //b에는 다시 a값 복사
}

void swapByReference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapByPointer(int* a, int* b) {
	if (a == nullptr || b == nullptr) {
		return; 
	}
	int temp = *a; // *a가 가리키는 곳의 값을 temp에 복제
	*a = *b; // *a가 가리키는 곳의 값을 *b가 가리키는 곳의 값으로 바꿈
	*b = temp; // 그리고*b는 자신이 가리키는 곳의 값을 temp로 함
}

int main() {

	int x = 10, y = 20;

	// call by value : x,y 상자에 들어있는 값을 a,b라는 새 상자를 복사해x,y 값을 넣고바꾸기에 원본에 영향이 없다.
	swapByValue(x, y);
	cout << x << "랑 " << y << "이다.";

	// call by reference : x,y 상자에 a,b라는 새 별명을 붙여서 x,y값을 바꾸기에 원본에 영향이 있다.
	swapByReference(x, y);
	cout << x << "이랑 " << y << "이다.";

	swapByPointer(&x, &y);
	cout << x << " " << y << endl;

	return 0;
}

#endif