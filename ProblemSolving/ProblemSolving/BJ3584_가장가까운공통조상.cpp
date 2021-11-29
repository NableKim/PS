#include <cstdio>
#include <vector>
using namespace std;

#define MAX_NODE 10000

int P[MAX_NODE + 1];		// Parent
int D[MAX_NODE+1];			// Depth
vector<int> E[MAX_NODE + 1];	// Edge

void init() {
	for (int i = 0; i <= MAX_NODE; i++) {
		P[i] = 0;
		D[i] = 0;
		E[i].clear();
	}
}

int getRootNodeNumber(int node) {
	while (P[node] != 0)
		node = P[node];
	return node;
}

void recursive_setDepth(int node, int depth) {
	D[node] = depth;

	for (int i = 0; i < E[node].size(); i++)
		recursive_setDepth(E[node][i], depth+1);
}

int main() {
	
	//freopen("Text.txt", "r", stdin);

	int T;
	scanf(" %d", &T);

	for (int tc = 1; tc <= T; tc++) {

		init();

		int N;
		scanf(" %d", &N);

		for (int n = 0, parent, child; n < N-1; n++) {
			scanf(" %d %d", &parent, &child);
			P[child] = parent;
			E[parent].push_back(child);	// 자식 노드로의 간선 정보를 저장
		}

		int a, b;
		scanf(" %d %d", &a, &b);

		// Root 노드 찾고
		int root = getRootNodeNumber(N);

		// 재귀적으로 각 노드의 높이값을 저장
		recursive_setDepth(root, 0);

		// a, b 깊이가 다르다면 동일하게 맞춰주기
		if (D[a] != D[b]) {
			
			// b가 더 큰 값을 갖도록 함
			if (D[a] > D[b]) {
				int tmp = a;
				a = b;
				b = tmp;
			}

			while (D[a] != D[b])
				b = P[b];
		}

		// a, b 노드가 다르면 같을 때까지 위로 한칸씩 올려주기
		while (a != b) {
			a = P[a];
			b = P[b];
		}
		
		printf("%d\n", a);
	}


	return 0;
}