#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<int> pick;

void print_pick() {
	for (int i = 0; i < 6; i++)
		printf("%d ", pick[i]);
	printf("\n");
}

void dfs(int depth) {
	
	if (pick.size() == 6) {
		print_pick();
		return;
	}

	// 가지치기
	if (N - depth + pick.size() < 6)
		return;

	for (int i = depth; i < N; i++) {
		pick.push_back(v[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main() {

	while (1) {
		
		scanf(" %d", &N);

		if (N == 0) break;

		v.clear();
		for (int i = 0, n; i < N; i++) {
			scanf(" %d", &n);
			v.push_back(n);
		}

		dfs(0);
		printf("\n");
	}

	return 0;
}