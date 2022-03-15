#include <cstdio>
using namespace std;

int arr[1001];
int N, answer;

void dfs(int depth, int cnt, int pre) {
	if (depth == N) {
		answer = answer < cnt ? cnt : answer;
		return;
	}

	if (cnt + N - depth <= answer)
		return;

	dfs(depth + 1, cnt, pre);
	if (arr[depth] > pre)
		dfs(depth + 1, cnt + 1, arr[depth]);
}

int main() {

	
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
		scanf(" %d", &arr[i]);
	
	dfs(0, 0, -1);
	
	printf("%d", answer);

	return 0;
}