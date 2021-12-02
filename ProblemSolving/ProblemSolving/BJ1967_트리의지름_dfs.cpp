#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Edge {
	int end, cost;
};

int leftNode, maxVal;
bool check[10001];
vector<Edge> E[10001];

void dfs(int node, int cost, bool visit) {
	for (int k = 0; k < E[node].size(); k++) {
		int nextNode = E[node][k].end;

		if (check[nextNode] == visit) continue;

		check[nextNode] = visit;
		int nextCost = cost + E[node][k].cost;
		if (maxVal < nextCost) {
			maxVal = nextCost;
			leftNode = nextNode;
		}
		dfs(nextNode, cost + E[node][k].cost, visit);
	}
}

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int start, end, cost;
		scanf(" %d %d %d", &start, &end, &cost);

		E[start].push_back({ end, cost });
		E[end].push_back({ start, cost });
	}


	// 트리의 지름에 나타내는 두 점 중 하나를 구하기
	check[1] = true;
	dfs(1, 0, true);

	maxVal = 0;
	check[leftNode] = false;
	dfs(leftNode, 0, false);

	printf("%d", maxVal);

	return 0;
}