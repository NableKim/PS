#include <cstdio>

int arr[4] = { 1, 2, 3, 4 };

void printArray() {
	for (int i = 0; i < 3; i++)
		printf("%d", arr[i]);
	printf("\n");
}

void swap(int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

// 재귀 함수를 이용한 순열 nPr 구하기
void nPr(int n, int r, int depth) {
	if (depth == r) {
		printArray();
		return;
	}
	
	for (int i = depth; i < n; i++) {
		swap(depth, i);
		nPr(n, r, depth + 1);
		swap(depth, i);
	}
}


int main() {

	nPr(4, 3, 0);	// nPr 구하기

	return 0;
}