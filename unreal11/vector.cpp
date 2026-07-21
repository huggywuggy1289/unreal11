#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};

	for (int num : numbers) {
		cout << num << " "; // 가로로 출력가능
	}

	// 데이터상자안을 직접 가리키면서 이동하는 것
	vector<int> sumbers = { 20,30,40 };
	for (vector<int>::iterator it = sumbers.begin(); it != sumbers.end(); --it) {
		cout << *it << " ";
	}

	// for (int i = 0; i < sumbers.size(); i++)
	return 0;
}
#endif