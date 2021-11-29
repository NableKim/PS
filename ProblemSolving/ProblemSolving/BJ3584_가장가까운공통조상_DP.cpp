#include <cstdio>
#include <vector>
using namespace std;

#define MAX_NODE 10000
#define LOG 15

int P[MAX_NODE + 1][LOG];		// Parent
int D[MAX_NODE + 1];			// Depth
vector<int> E[MAX_NODE + 1];	// Edge

void init() {
	for (int i = 0; i <= MAX_NODE; i++) {
		for(int j=0; j<LOG; j++)
			P[i][j] = 0;
		D[i] = 0;
		E[i].clear();
	}
	D[0] = -1;
}

int getRootNodeNumber(int node) {
	while (P[node][0] != 0)
		node = P[node][0];
	return node;
}

void setDepthNParent(int node, int depth) {

	// 깊이값 저장
	D[node] = depth;

	// 조상 노드 정보 저장
	for (int i = 1; i < LOG; i++) {
		int anc = P[node][i - 1];
		P[node][i] = P[anc][i - 1];
	}

	for (int i = 0; i < E[node].size(); i++)
		setDepthNParent(E[node][i], depth + 1);
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int T;
	scanf(" %d", &T);

	for (int tc = 1; tc <= T; tc++) {

		init();

		int N;
		scanf(" %d", &N);

		for (int n = 0, parent, child; n < N - 1; n++) {
			scanf(" %d %d", &parent, &child);
			P[child][0] = parent;
			E[parent].push_back(child);	// 자식 노드로의 간선 정보를 저장
		}

		int a, b;
		scanf(" %d %d", &a, &b);

		// Root 노드 찾고
		int root = getRootNodeNumber(N);

		// 재귀적으로 각 노드의 깊이값, 조상노드 정보를 저장
		setDepthNParent(root, 0);

		// a, b 깊이가 다르다면 동일하게 맞춰주기
		if (D[a] != D[b]) {

			// b가 더 큰 값을 갖도록 함
			if (D[a] > D[b]) {
				int tmp = a;
				a = b;
				b = tmp;
			}

			for (int i = LOG-1; i >= 0; i--) {
				if (D[a] <= D[P[b][i]])
					b = P[b][i];
			}
		}

		// a, b 노드가 다르면 같을 때까지 위로 한칸씩 올려주기
		int answer = a;
		if (a != b) {
			for (int i = LOG-1; i >= 0; i--) {
				if (P[a][i] != P[b][i]) {
					a = P[a][i];
					b = P[b][i];
				}
			}
			answer = P[a][0];
		}

		printf("%d\n", answer);
	}

	return 0;
}