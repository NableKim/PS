#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define NODE_NUN 32000

struct P {
	int degree, idx;
};

bool operator <(P a, P b) {
	if (a.degree == b.degree)
		return a.idx > b.idx;
	return a.degree > b.degree;
}

int Degree[NODE_NUN + 1];
bool Check[NODE_NUN + 1];
vector<int> E[NODE_NUN + 1];
priority_queue<P> pq;

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, M;
	scanf(" %d %d", &N, &M);
	
	for (int i = 0, a, b; i < M; i++) {
		scanf("%d %d", &a, &b);
		E[a].push_back(b);	// 간선 정보 저장
		Degree[b]++;		// b의 차수 증가
	}

	for (int i = 1; i <= N; i++) {
		pq.push({ Degree[i], i });
	}

	int cnt = 0;
	while (!pq.empty()) {
		int node = pq.top().idx;
		pq.pop();
	
		if (!Check[node]) {
			Check[node] = true;
			printf("%d ", node);
			cnt++;

			if (cnt == N) break;

			for (int k = 0; k < E[node].size(); k++) {
				int nextNode = E[node][k];
				Degree[nextNode]--;
				pq.push({ Degree[nextNode], nextNode });
			}
		}
	}

	return 0;
}