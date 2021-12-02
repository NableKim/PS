#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int end, cost;
};

vector<Edge> E[10001];

Edge bfs(int node) {
	int check[10001] = { 0, };
	check[node] = 1;

	queue<int> q;
	q.push(node);

	int maxNode = node;
	int maxVal = 1;

	while (!q.empty()) {
		int curNode = q.front(); q.pop();

		for (int k = 0; k < E[curNode].size(); k++) {
			int nextNode = E[curNode][k].end;

			if (check[nextNode]) continue;
			check[nextNode] = check[curNode] + E[curNode][k].cost;
			q.push(nextNode);

			if (check[nextNode] > maxVal) {
				maxNode = nextNode;
				maxVal = check[nextNode];
			}
		}
	}

	return { maxNode, maxVal - 1 };
}

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N-1; i++) {
		int start, end, cost;
		scanf(" %d %d %d", &start, &end, &cost);

		E[start].push_back({ end, cost });
		E[end].push_back({ start, cost });
	}


	// 트리의 지름에 나타내는 두 점 중 하나를 구하기
	Edge firstPoint = bfs(1);

	Edge secondPoint = bfs(firstPoint.end);

	printf("%d", secondPoint.cost);

	return 0;
}