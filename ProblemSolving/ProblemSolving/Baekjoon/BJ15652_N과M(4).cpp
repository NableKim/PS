#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P {
	int val, cnt;
};

int A[8];
vector<P> pick;
int N, M;

void dfs(int depth, int remain) {
	if (remain == 0) {
		for (int i = 0; i < pick.size(); i++) {
			for(int j=0; j<pick[i].cnt; j++)
				printf("%d ", pick[i].val);
		}
		printf("\n");
		
		return;
	}

	for (int i = depth; i < N; i++) {
		for (int j = remain; j > 0; j--) {
			pick.push_back({ A[i], j });
			dfs(i+1, remain-j);
			pick.pop_back();
		}
	}
}

int main() {

	//freopen("Text.txt", "r", stdin);
	
	scanf(" %d %d", &N, &M);

	for (int i = 0; i < N; i++)
		A[i] = i + 1;

	sort(A, A + N);

	dfs(0, M);

	return 0;
}