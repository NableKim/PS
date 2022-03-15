#include <cstdio>
using namespace std;

#define SWITCH_NUM 200

bool B[SWITCH_NUM];

void male_func(int n, int idx) {
	for (int i = idx - 1; i < n; i+=idx)
		B[i] = !B[i];
}

int getSymmetryLength(int n, int idx) {

	int left = idx - 2;
	int right = idx;

	int len = 0;
	while (left >= 0 && right < n) {
		if (B[left] != B[right])
			break;
		left--;
		right++;
		len++;
	}
	return len;
}

void female_func(int n, int idx) {
	int len = getSymmetryLength(n, idx);
	for (int i = idx - len - 1; i < idx + len; i++)
		B[i] = !B[i];
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
		scanf(" %d", &B[i]);

	int M;
	scanf(" %d", &M);

	for (int i = 0, a, b; i < M; i++) {
		scanf(" %d %d", &a, &b);

		if (a == 1) 
			male_func(N, b);
		else 
			female_func(N, b);
	}

	printf("%d ", B[0]);
	for (int i = 1; i < N; i++) {
		if(i%20==0) printf("\n");
		printf("%d ", B[i]);
	}

	return 0;
}