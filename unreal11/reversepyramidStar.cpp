#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	int a;
	cin >> a;

	vector<char> arr(a);
	int size = arr.size();

	for (int i = size -1 ; i >= 0; i--) 
	{
		
		int space = size - i - 1;
		int count = i * 2 + 1; // 별 개수는 홀수이므로

		for (int j = 0; j < space; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < count; j++) 
		{
			cout << "*";
		}

		cout << '\n';
	}

	return 0;

}
#endif
/*
7
5
3
1
*/