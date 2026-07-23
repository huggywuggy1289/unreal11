#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int a;
	cin >> a;

	//입력값에 맞춰 크기가 달라지는 배열을 만들고 싶을 때
	vector<char> arr(a);
	int size = arr.size();

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
	return 0;
}
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