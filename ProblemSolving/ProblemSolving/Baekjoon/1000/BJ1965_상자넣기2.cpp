/*
배열 Arr이 주어졌을 때
LIS[i] = Arr[i] 원소를 포함한 LIS 최장 길이
	= max( LIS[0~(i-1)] ) + 1 
	= i 이전의 원소들로 만들 수 있는 LIS를 구하고,
	  맨 뒤에 i번째 원소를 포함시켰을때의 길이를 구한다.
	  (단, i번째 원소가 이전값보다 커야함) 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define BOX_NUM 1000

int LIS[BOX_NUM];
int B[BOX_NUM];

int main() {
	
	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %d", &B[i]);
	}

	for (int i = 0; i < N; i++) {
		LIS[i] = 1;
		for (int j = 0; j < i; j++) {
			if(B[j] < B[i])
				LIS[i] = max(LIS[i], LIS[j] + 1);
		}
	}

	int maxVal = 1;
	for (int i = 0; i < N; i++)
		maxVal = max(LIS[i], maxVal);

	printf("%d", maxVal);

	return 0;
}