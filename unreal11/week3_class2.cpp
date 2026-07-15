#include <iostream>
using namespace std;

int main() {
	int *ptr = new int(10); // int(10)이라는 객체가 담긴 힙의 주솟값을 가리키는 ptr포인터

	cout << "힙에 있는 int(10)의 주솟값 : " << ptr << endl;
	cout << "스택에 저장되어있는 ptr의 주솟값 : " << &ptr << endl;
	cout << "그 주소에 가서 객체에 들어간 값을 꺼냄 : " << *ptr << endl;

	delete ptr;
	return 0;
}