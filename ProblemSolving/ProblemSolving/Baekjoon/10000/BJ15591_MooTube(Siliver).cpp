#include <cstdio>
#include <vector>
using namespace std;

#define MAX_NODE 5001
#define INF 1000000003

struct INFO {
	int node, cost;
};

int D[MAX_NODE][MAX_NODE];
vector<INFO> E[MAX_NODE];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

void dfs(int startNode, int curNode, int preNode, int minCost) {

	// 현재 노드를 기준으로 이웃한 노드를 확인
	for (int i = 0; i < E[curNode].size(); i++) {
		int nextNode = E[curNode][i].node;
		int nextCost = E[curNode][i].cost;

		if (nextNode == preNode) continue;

		if (minCost > nextCost) {
			D[startNode][nextNode] = nextCost;
			dfs(startNode, nextNode, curNode, nextCost);
		}
		else {
			D[startNode][nextNode] = minCost;
			dfs(startNode, nextNode, curNode, minCost);
		}
	}
}

int main() {

	freopen("Text.txt", "r", stdin);
	
	int N, Q;
	scanf(" %d %d", &N, &Q);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			D[i][j] = INF;
		}
	}

	for (int i = 0, a, b, c; i < N-1; i++) {
		scanf(" %d %d %d", &a, &b, &c);
		E[a].push_back({ b, c });
		E[b].push_back({ a, c });
	}

	for (int i = 1; i <= N; i++)
		dfs(i, i, 0, INF);
	
	for (int i = 0, a, b; i < Q; i++) {
		scanf(" %d %d", &a, &b);

		int answer = 0;
		for (int v = 1; v <= N; v++) {
			if (b == v) continue;
			if (a <= D[b][v]) answer++;
		}

		printf("%d\n", answer);
	}
}