#include <cstdio>

int arr[4] = { 1, 2, 3, 4 };
int t[4];

void printArray() {
	for (int i = 0; i < 3; i++)
		printf("%d", t[i]);
	printf("\n");
}

void swap(int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

/*
* 중복순열의 점화식을 이용하여 nPIr 구하기
* @refer : nPIr = n * (n)P(r-1)
* @params
	n : 숫자의 개수
	r : 앞으로 뽑아야할 개수
	q : 뽑을 숫자의 개수
*/
void nPIr(int n, int r, int q) {
	if (r == 0) {
		printArray();
		return;
	}

	// arr 맨 뒤자리부터 올 수 있는 숫자를 정해주기
	for (int i = n - 1; i >= 0; i--) {
		swap(i, n - 1);	// n-1 번째 자리에 i번째 원소를 위치시킴
		t[r - 1] = arr[n - 1];	// 뽑은 숫자를 출력용 순열 t에 저장
		nPIr(n, r - 1, q);
		swap(i, n - 1); // 복구
	}
}

int main() {

	nPIr(4, 3, 3);

	return 0;
}