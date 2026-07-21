#include <iostream>
#include <string>

using namespace std;

int main() {

	int* ptr = new int(10);

	cout << "동적으로 빌린 방의 값 : " << * ptr << endl;
	cout << "동적으로 빌린 방의 주소값 : " << ptr << endl;

	 delete ptr;

	 ptr = nullptr;
	 if (ptr != nullptr) {
		 cout << *ptr << endl;
	 }

	return 0;
}