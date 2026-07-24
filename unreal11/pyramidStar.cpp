#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int a;
	cin >> a;

	// [방법 1] 동적배열할당
	//vector<char> arr(a);
	//int size = arr.size();

	// [방법 2] 포인터로 일반배열 동적 할당
	 char* arr = new char[a];
	 // int size = sizeof(arr)/sizeof(arr[0]); // 포인터로 할당한건 포인터크기로 size되니 크기가 고정된다.
	 int size = a; // 그냥 이렇게 하면 된다.

	for (int i = 0; i < size; i++) 
	{
		int space = size - i - 1;
		int count = 2 * i + 1; // 원하는 개수는 출력 가능.

		for (int j = 0; j < space; j++) {
			cout << " ";
		}

		// 그 개수만큼 반복할려면
		for (int j = 0; j < count; j++) {
			cout << "*";
		}
		cout << '\n';
	}

	delete[] arr;
	arr = nullptr;
	return 0;
}
#endif
/*


입력: n = 4
출력:
   *
  ***
 *****
*******

4를 입력했으면
4만큼 돌면서

i     j
0일때 1
1일때 3
2일때 5
3일때 7

*/