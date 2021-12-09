#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_NODE 10001

struct EDGE {
	int end, cost;
};

vector<EDGE> v[MAX_NODE];
bool candi[MAX_NODE];
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

	bool candi_bk[MAX_NODE] = { false, };
	memcpy(candi_bk, candi, sizeof(candi));

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && candi[i]) {
			
			// i�� ��带 ���� ���� �湮�� ���̸�
			visited[i] = true;		
			for (int j = 0; j < v[i].size(); j++)
				candi[v[i][j].end] = true;
			
			for (int j = 0; j < v[i].size(); j++) {
				int node = v[i][j].end;
				if (visited[node]) {
					int nextLevel = curLevel;
					if (v[i][j].cost > curLevel)
						nextLevel = v[i][j].cost;
					dfs(i, visitCnt + 1, visited, nextLevel);
			
					memcpy(candi, candi_bk, sizeof(candi));
				}
			}
				
			visited[i] = false;
		}
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
	
	for (int i = 0; i < v[N].size(); i++)
		candi[v[N][i].end] = true;

	dfs(N, 1, visited, 0);

	cout << answer;

	return 0;
}