#include <cstdio>
using namespace std;

#define N_MAX 10000

int A[N_MAX];

int main() {

	int N, M;
	scanf(" %d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf(" %d", &A[i]);

	int answer = 0;
	int left = 0;
	int right = 0;
	int sum = A[left];
	while (1) {
		if (sum <= M) {
			if (sum == M) answer++;
			right++;
			if (right == N) break;
			sum += A[right];
		}
		else {
			sum -= A[left];
			left++;
			if (left == N) break;
		}
	}

	printf("%d", answer);

}