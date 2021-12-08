#include <cstdio>
using namespace std;

int C[100];
int N, K, answer;
int D[10001];

int main() {

	//freopen("Text.txt", "r", stdin);

	scanf(" %d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		scanf(" %d", &C[i]);
	
	D[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= K; k++) {
			if (k >= C[i])
				D[k] = D[k - C[i]] + D[k];
		}
	}

	printf("%d", D[K]);

	return 0;
}