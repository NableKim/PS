#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define NODE_NUN 32000

int D[NODE_NUN + 1];
vector<int> E[NODE_NUN + 1];
bool check[NODE_NUN + 1];

void explorer(int node) {
	if (D[node] == 0) {
		printf("%d ", node);
		check[node] = true;
		for (int k = 0; k < E[node].size(); k++) {
			int nextNode = E[node][k];
			D[nextNode]--;
			explorer(nextNode);
		}
	}
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, M;
	scanf(" %d %d", &N, &M);
	
	for (int i = 0, a, b; i < M; i++) {
		scanf("%d %d", &a, &b);
		E[a].push_back(b);	// 간선 정보 저장
		D[b]++;	// b의 차수 증가
	}

	for (int i = 1; i <= N; i++) {
		if (E[i].size() >= 2)
			sort(E[i].begin(), E[i].end());
	}

	for (int i = 1; i <= N; i++) {
		if(!check[i])
			explorer(i);
	}

	return 0;
}