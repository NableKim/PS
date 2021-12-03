#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_NUM 100000
#define INF 2000000001

int A[MAX_NUM];

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %d", &A[i]);
	}

	sort(A, A + N);

	int l = 0, r = N-1;
	long long diffMin = INF;
	int a, b;
	while (l!=r) {
		long long sum = (long long)A[l] + (long long)A[r];
		if (abs(sum) < diffMin) {
			diffMin = abs(sum);
			a = A[l];
			b = A[r];
		}
		if (sum == 0) {
			a = A[l];
			b = A[r];
			break;
		}
		else if (sum > 0)
			r--;
		else
			l++;
	}

	printf("%d %d", a, b);
	return 0;
}