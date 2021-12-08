#include <cstdio>
using namespace std;

int C[100];
int N, K, answer;
int D[100][10001];

int getD(int kind, int sum) {

	if (D[kind][sum])
		return D[kind][sum];

	if (C[kind] > sum) {
		return getD(kind - 1, sum);
	}
	else {
		return getD(kind, sum - C[kind]) + getD(kind - 1, sum);
	}
}


int main() {

	//freopen("Text.txt", "r", stdin);

	scanf(" %d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf(" %d", &C[i]);
	
	for (int i = 0; i <= K; i++) {
		if(i % C[0] == 0)
			D[0][i] = 1;
	}
	printf("%d", getD(N-1, K));

	return 0;
}