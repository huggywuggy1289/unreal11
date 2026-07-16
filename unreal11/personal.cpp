#include <iostream>
#include <stdio.h>

// A[p ~ q] / A[q+1 ~ r]
void merge(int A[], int p, int q, int r) {

	// 왼, 오 요소개수(배열 사이즈)
	int left = q - p + 1;
	int right = r - (q + 1) - 1;

	// 요소에 맞게 임시배열사이즈 지정
	int* L = new int[left];
	int* R = new int[right];

	// 왼, 오 임시배열에 있는 값이 실제 A에 들어갈때의 위치 정렬
	for (int i = 0; i < left; i++) L[i] = A[p + i];
	for (int j = q + 1; j < right; j++) R[j] = A[(q + 1) + j];

	// 각각 L,R,A배열의 현재 위치(각각의 배열에서는 첫번째 원소 인덱스가 전부 0이올시다)
	int i = 0, j = 0, k = 0;

	// 두 배열이 다 정렬된 상태이니 이걸 다시 A에 넣어야함.
	while (i < left && j < right) { // 각자 인덱스가 서로의 배열을 침범하지않는 상태에서
		if (L[i] <= R[j]) {
			A[k++] = L[i++]; // A배열에 더 작은 왼쪽 원소넣어주기
		}
		else {
			A[k++] = R[i++];
		}

	}

	// 다 정렬하고 원소 1개뿐이면 그냥k에 넣기
	// = 인덱스가 아직 왼쪽 배열을 덜 돌았다면(한개의 원소가 남았다면)
	while (i < left) {
		A[k++] = L[i++];
	}
	while (j < right) {
		A[k++] = R[i++];
	}
	delete[] L;
	delete[] R;
}

void mergesolution() {


}
int main() {

}