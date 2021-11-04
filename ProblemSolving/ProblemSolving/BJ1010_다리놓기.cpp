/*
Top Down 방식의 DP문제로 반복해를 구하지않도록 구현
*/

#include <iostream>
using namespace std;

int MEMO[31][31];

int combination(int M, int N) {
	if (M < N)
		return 0;

	if (M == N || N==0)
		return 1;

	if (MEMO[M][N] >= 1)
		return MEMO[M][N];

	return MEMO[M][N] = combination(M - 1, N) + combination(M - 1, N - 1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;

		cout << combination(M, N) << "\n";
	}

	return 0;
}