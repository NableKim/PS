#include <cstdio>

int arr[4] = { 1, 2, 3, 4 };
int t[4];

void printArray() {
	for (int i = 0; i < 3; i++)
		printf("%d", t[i]);
	printf("\n");
}

/*
* 조합 nCr 구하기
* @refer 조합의 점화식 : nCr = (n-1)C(r-1) + (n-1)C(r)
* @params 
	n : 전체 숫자의 개수
	r : 앞으로 몇개 더 골라야하는가
	q : 최초 r의 백업
*/
void nCr(int n, int r, int q){
	
	if (r == 0) {
		printArray();
		return;
	}
	else if (n < r)
		return;
	
	t[r - 1] = arr[n-1];
	nCr(n - 1, r - 1, q);
	nCr(n - 1, r, q);
}

int main() {
	nCr(4, 3, 3);
	return 0;
}