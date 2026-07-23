#define RUN_THIS 0
#if RUN_THIS

#include <iostream>

using namespace std;

int main() {

	// 초급
	
	int numbers[5] = { 12,34, 56, 78, 90 };

	int s = sizeof(numbers)/sizeof(numbers[0]);
	cout << "배열의 총 길이 : " << s << endl; //5

	cout << numbers[1] << " ";
	cout << numbers[2] << " ";
	cout << numbers[4] << " ";

	// 중급

	// https://learn.microsoft.com/ko-kr/cpp/error-messages/compiler-errors-1/compiler-error-c2372?view=msvc-170&f1url=%3FappId%3DDev17IDEF1%26l%3DKO-KR%26k%3Dk%28C2372%29%26rd%3Dtrue
	// 배열과 포인터의 식별자는 같으면 안됩니다
	int arr0[] = { 12, 34, 56, 78, 90 };
	int* arr = &arr0[0];


	// 이 둘이 값이 같고
	cout << "arr[0]에 들어 있는 값 : " << arr[0] << '\n';
	cout << "*arr이 가리키는 값 : " << *arr << '\n';

	// 이 둘이 값이 같다
	cout << "arr[0]의 메모리주소 : " << &arr[0] << '\n'; // 배열의 주솟값
	cout << "arr이 가지고 있는 주소값 : " << arr << '\n'; // 배열의 맨처음 값이 들어있는 메모리 주소값

	// 상급

	// a를 입력받음
	int a;
	cout << "\n아파트 층수를 입력하세요 : " << endl;
	cin >> a;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "적절한 타입이 아닙니다." << endl;
		return 0;
	}
	// 크기만큼 동적으로 공간 할당받음
	int* ptr = new int[a];

	// for문 돌려서 1,2번째 요소 입력받기
	for (int i = 0; i < a; i++) {

		int num;

		cin >> num; //입력받은 값이
		ptr[i] = num; // 그값이 된다.
	}
	//cout << ptr+1 << " " << ptr+2 << endl; // 주솟값 출력됨
	cout << ptr[1] << " " << ptr[2] << endl; // 적절한 값 출력됨
	// 버퍼의 읽기 가능한 범위는 버퍼에서 읽는 데 사용되는 인덱스보다 작을 수 있다.

	delete[] ptr;
	ptr = nullptr;

}
#endif

/*
배열의 총 길이 : 5
34 56 90 arr[0]에 들어 있는 값 : 12
*arr이 가리키는 값 : 12
arr[0]의 메모리주소 : 000000F5108FF768
arr이 가지고 있는 주소값 : 000000F5108FF768

아파트 층수를 입력하세요 :
4
1
2
3
4
2 3
*/