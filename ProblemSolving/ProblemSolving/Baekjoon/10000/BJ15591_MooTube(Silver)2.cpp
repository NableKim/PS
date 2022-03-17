#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NODE 5001
#define INF 1000000003

struct INFO {
	int node, cost;
};

vector<INFO> E[MAX_NODE];
int D[MAX_NODE][MAX_NODE];
int visited[MAX_NODE];
int N, Q;

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

void init() {
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
}

void bfs(int startNode) {

	init();
	queue<INFO> q;
	q.push({ startNode, INF });
	visited[startNode] = INF;

	while (!q.empty()) {

		INFO front = q.front();
		q.pop();

		for (int k = 0; k < E[front.node].size(); k++) {
			int nextNode = E[front.node][k].node;
			int nextCost = E[front.node][k].cost;

			if (visited[nextNode])
				continue;

			int tmp = front.cost > nextCost ? nextCost : front.cost;
			q.push({ nextNode, tmp });
			visited[nextNode] = tmp;
		}
	}

	visited[startNode] = 0;
	for (int i = 1; i <= N; i++) {
		D[startNode][i] = visited[i];
	}
}

int main() {

	//freopen("Text.txt", "r", stdin);

	scanf(" %d %d", &N, &Q);

	for (int i = 0, a, b, c; i < N - 1; i++) {
		scanf(" %d %d %d", &a, &b, &c);
		E[a].push_back({ b, c });
		E[b].push_back({ a, c });
	}

	for (int i = 1; i <= N; i++)
		bfs(i);

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