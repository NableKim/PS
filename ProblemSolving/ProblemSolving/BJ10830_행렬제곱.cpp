#include <cstdio>

#define DIV 1000

using namespace std;

struct MATRIX {
	int M[5][5];
};

MATRIX A;
int N;

MATRIX multiple_matrix(MATRIX a, MATRIX b) {
	MATRIX result;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int sum = 0;
			for (int i = 0; i < N; i++) {
				sum += (a.M[y][i] * b.M[i][x])%DIV;
				sum %= DIV;
			}
			result.M[y][x] = sum;
		}
	}

	return result;
}

MATRIX dfs(long long indices) {
	if (indices == 1)
		return A;

	long long half = indices / 2;
	MATRIX tmp = dfs(half);
	if (indices % 2 == 0)
		return multiple_matrix(tmp, tmp);
	
	else
		return multiple_matrix(A, multiple_matrix(tmp, tmp));
}

int main() {

	//freopen("Text.txt", "r", stdin);

	long long B;
	scanf(" %d %lld", &N, &B);
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf(" %d", &A.M[y][x]);
			A.M[y][x] %= DIV;
		}
	}

	MATRIX result = dfs(B);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", result.M[y][x]);
		}
		printf("\n");
	}

	return 0;
}