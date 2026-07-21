#define RUN_THIS 0
#if RUN_THIS


#include <iostream>
#include <string>

using namespace std;

int main() {

	int* ptr = new int(10);

	cout << "동적으로 빌린 방의 값 : " << * ptr << endl;
	cout << "동적으로 빌린 방의 주소값 : " << ptr << endl;

	 delete ptr;

	 ptr = nullptr; // "나 이거 해제했어!"라고 표시


	 // 나중에 다른 곳에서 ptr을 쓰려고 할 때
	 if (ptr != nullptr) {
		 cout << *ptr << endl; // // 안전할 때만 접근!
	 }
	 else {
		 cout << "이미 해제된 포인터라 접근하지 않습니다." << endl;
	 }

	 int* arr = new int[5](); //()를 붙이면 나머지 방도 전부 0으로 자동 초기화 선언하지 않을경우 -842150451 -842150451 -842150451 이러한 쓰레기값 추출됨
	 arr[0] = 1;
	 arr[1] = 2;
	 arr[2] = 3;
	 arr[3] = 4;
	 arr[4] = 5;

	 // arr[5] = 10; // C6386: 버퍼 오버런 창뜸.(할당된 영역을 넘어선 접근)

	 for (int i = 0; i < 5; i++) {
		 cout << arr[i] << " ";
	 }

	 delete[] arr;

	return 0;
}
#endif