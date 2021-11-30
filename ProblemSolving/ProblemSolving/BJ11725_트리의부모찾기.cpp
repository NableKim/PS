#include <cstdio>
#include <vector>
using namespace std;

#define MAX_NODE 100001

vector<int> Edge[MAX_NODE];
int Parent[MAX_NODE];

void dfs(int node, int parent) {
	for (int i = 0; i < Edge[node].size(); i++) {
		int nextNode = Edge[node][i];
		if (nextNode == parent) continue;
		Parent[nextNode] = node;
		dfs(nextNode, node);
	}
}

int main() {

	int N;
	scanf(" %d", &N);

	for (int i = 0, a, b; i < N - 1; i++) {
		scanf(" %d %d", &a, &b);
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}

	dfs(1 ,0);

	for (int i = 2; i <= N; i++)
		printf("%d\n", Parent[i]);

	return 0;
}