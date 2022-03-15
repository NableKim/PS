#include <cstdio>
using namespace std;

#define MAX_NUM 100000

int A[MAX_NUM];

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, S;
	scanf(" %d %d", &N, &S);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf(" %d", &A[i]);
		sum += A[i];
	}

	if (sum < S) {
		printf("0");
		return 0;
	}

	int l = 0, r = 0;
	sum = A[l];
	int minLen = N;
	while (1) {
		if (sum >= S) {
			int len = r - l + 1;
			minLen = len < minLen ? len : minLen;
			sum -= A[l];
			l++;
			if (l > r) break;
		}
		else {
			r++;
			if (r >= N) break;
			sum += A[r];
		}
	}

	printf("%d", minLen);
	return 0;
}