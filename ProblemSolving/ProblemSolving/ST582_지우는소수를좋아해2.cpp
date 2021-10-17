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

// ���� ��� ����̰�, ���ݱ��� �湮�� ������ ��̰�, �湮�� ������ ����� �����̸�, ���ݱ����� ������ �����ΰ�
void dfs(int curNode, int visitCnt, bool* visited, int curLevel) {

	if (curLevel >= answer) return;

	if (visitCnt == N) {
		if (curLevel < answer && isPrimeNumber(curLevel)) {
			answer = curLevel;
		}
		return;
	}

	for (int i = 0; i < v[curNode].size(); i++) {

		// �̹� �湮�ߴٸ� ��ŵ
		if (visited[v[curNode][i].end]) continue;

		// �湮üũ
		visited[v[curNode][i].end] = true;

		int nextLevel = curLevel;
		if (v[curNode][i].cost > curLevel)
			nextLevel = v[curNode][i].cost;
		dfs(v[curNode][i].end, visitCnt + 1, visited, nextLevel);

		// �̹湮���� ����
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