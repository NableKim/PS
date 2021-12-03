#include <cstdio>
#include <string>
using namespace std;

#define MAX_NUM 201
#define INF 1000000001

long long C[MAX_NUM][MAX_NUM];

long long Combination(int n, int r) {
	if (n < r)
		return 0;
	else if (r == 1)
		return C[n][r] = n;
	else if (r == 0)
		return C[n][r] = 1;

	if (C[n][r])
		return C[n][r];

	long long left = Combination(n - 1, r - 1);
	long long right = Combination(n - 1, r);
	if (left + right >= INF)
		return C[n][r] = INF;
	return C[n][r]= left+right;
}

string dfs(int n, int m, long long k) {

	if (n == 0) {
		string tmp = "";
		for (int i = 0; i < m; i++)
			tmp += "z";
		return tmp;
	}

	// a가 처음에 올 수 있다면
	long long nCr = Combination(n + m - 1, n - 1);
	if (nCr >= k) {
		return "a" + dfs(n - 1, m, k);
	}
	else {
		return "z" + dfs(n, m-1, k- nCr);
	}
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, M;
	long long K;
	scanf("%d %d %lld", &N, &M, &K);

	if (Combination(N + M, N) < K)
		printf("-1");
	else {
		string answer = dfs(N, M, K);
		printf("%s", answer.c_str());
	}

	return 0;
}