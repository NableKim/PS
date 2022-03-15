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
	for (int base = 0; base < N; base++) {
		int sum = 0;
		for (int len = 1; len < N + 1 - base; len++) {
			sum += A[base + len - 1];
			if (sum >= M) {
				if (sum == M) answer++;
				break;
			}
		}
	}
	
	printf("%d", answer);

}