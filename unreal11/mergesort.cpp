#include <iostream>
#include <stdio.h>
using namespace std;

/*
// A[p ~ q] / A[q+1 ~ r]
void merge(int A[], int p, int q, int r) {

	// 왼, 오 요소개수(배열 사이즈)
	int left = q - p + 1;
	int right = r - q;

	// 요소에 맞게 임시배열사이즈 지정
	int* L = new int[left];
	int* R = new int[right];

	// 왼, 오 임시배열에 있는 값이 실제 A에 들어갈때의 위치 정렬
	// 각자 다른배열이니 인덱스는 둘다 0으로 해야 쓰레기값 참조가 안된다.
	for (int i = 0; i < left; i++) L[i] = A[p + i];
	for (int j = 0; j < right; j++) R[j] = A[(q + 1) + j];

	// 각각 L,R,A배열의 현재 위치(각각의 배열에서는 첫번째 원소 인덱스가 전부 0이올시다)
	int i = 0, j = 0, k = p;

	// 두 배열이 다 정렬된 상태이니 이걸 다시 A에 넣어야함.
	while (i < left && j < right) 
	{ 
		// 각자 인덱스가 서로의 배열을 침범하지않는 상태에서
		if (L[i] <= R[j]) 
		{
			A[k++] = L[i++]; // A배열에 더 작은 왼쪽 원소넣어주기
		}
		else 
		{
			A[k++] = R[j++];
		}

	}

	// 다 정렬하고 원소 1개뿐이면 그냥k에 넣기
	// = 인덱스가 아직 왼쪽 배열을 덜 돌았다면(한개의 원소가 남았다면)
	while (i < left) {
		A[k++] = L[i++];
	}
	while (j < right) {
		A[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int A[], int p, int r) { // 배열, 첫번째 원소, 마지막 원소


	if (p >= r) {
		return;
	}

	int q = (p + r) / 2;

	mergeSort(A ,p, q);
	mergeSort(A, q+1, r);
	merge(A, p, q, r);
}

int main() {

	int A[] = { 43,2,65,3,1,5,7,3,8,2,6,3,87 };
	int n = sizeof(A) / sizeof(A[0]);

	cout << "오름차순 나열결과 : " << endl;
	for (int i = 0; i < n; i++) {

		mergeSort(A, 0, n-1);
		cout << A[i] << endl; // 이렇게 하면 배열의 주소만 찍힌다
	}
	cout << "첫번째 원소 : " << A[0] << endl;
	cout << "마지막 원소 : " << A[n - 1] << endl;
	
	return 0;
}
 */

// 1차 버그 : for (int j = q+1; j < right; j++) R[j] = A[(q + 1) + j]; << j가 올바르지않아 쓰레기값 참조
/*
오름차순 나열결과 : -842150451
첫번째 원소 : -842150451
마지막 원소 : 43
*/

// 2차 결과 : 

/*
오름차순 나열결과 : 1
오름차순 나열결과 : 2
오름차순 나열결과 : 2
오름차순 나열결과 : 3
오름차순 나열결과 : 3
오름차순 나열결과 : 3
오름차순 나열결과 : 5
오름차순 나열결과 : 6
오름차순 나열결과 : 7
오름차순 나열결과 : 8
오름차순 나열결과 : 43
오름차순 나열결과 : 65
오름차순 나열결과 : 87
첫번째 원소 : 1
마지막 원소 : 87
*/