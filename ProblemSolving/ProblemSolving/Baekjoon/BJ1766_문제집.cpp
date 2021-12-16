#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define NODE_NUN 32000

int Degree[NODE_NUN + 1];
vector<int> E[NODE_NUN + 1];
priority_queue<int, vector<int>, greater<int>> pq;

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
		if(Degree[i]==0)
			pq.push({ i });
	}

	for (int i = 1; i <= N; i++) {
		int node = pq.top(); pq.pop();
		printf("%d ", node);
			
		for (int k = 0; k < E[node].size(); k++) {
			int nextNode = E[node][k];
			Degree[nextNode]--;
			if(Degree[nextNode]==0)
				pq.push(nextNode);
		}
	}

	return 0;
}