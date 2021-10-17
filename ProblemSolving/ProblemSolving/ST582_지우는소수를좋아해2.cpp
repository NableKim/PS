#include <iostream>
#include <vector>
using namespace std;

#define MAX_NODE 10001

struct EDGE {
	int end, cost;
};

vector<EDGE> v[MAX_NODE];
int answer = 1000000002;
int N, M;

bool isPrimeNumber(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// 현재 몇번 노드이고, 지금까지 방문한 노드들은 몇개이고, 방문한 노드들의 목록은 무엇이며, 지금까지의 레벨은 무엇인가
void dfs(int curNode, int visitCnt, bool* visited, int curLevel) {

	if (curLevel >= answer) return;

	if (visitCnt == N) {
		if (curLevel < answer && isPrimeNumber(curLevel)) {
			answer = curLevel;
		}
		return;
	}

	for (int i = 0; i < v[curNode].size(); i++) {

		// 이미 방문했다면 스킵
		if (visited[v[curNode][i].end]) continue;

		// 방문체크
		visited[v[curNode][i].end] = true;

		int nextLevel = curLevel;
		if (v[curNode][i].cost > curLevel)
			nextLevel = v[curNode][i].cost;
		dfs(v[curNode][i].end, visitCnt + 1, visited, nextLevel);

		// 미방문으로 복원
		visited[v[curNode][i].end] = false;
	}
}

int main(int argc, char** argv)
{
	//freopen("Text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	bool visited[MAX_NODE] = { false, };
	visited[N] = true;

	dfs(N, 1, visited, 0);

	cout << answer;

	return 0;
}