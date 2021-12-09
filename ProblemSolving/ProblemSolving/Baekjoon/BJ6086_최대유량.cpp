#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_NODE 52
#define INF 1000000

using namespace std;

int C[MAX_NODE][MAX_NODE];
int F[MAX_NODE][MAX_NODE];
int D[MAX_NODE];
vector<int> E[MAX_NODE];
int answer;

int charToInt(char a) {
	if (a >= 'A' && a <= 'Z')
		return a - 'A';
	else
		return a - 'a' + 26;
}

void maxFlow(int start, int end) {

	while (1) {

		fill(D, D + MAX_NODE, -1);

		queue<int> q;
		q.push(start);
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (int i = 0; i < E[node].size(); i++) {
				int nextNode = E[node][i];

				if (D[nextNode] == -1 && C[node][nextNode] - F[node][nextNode] > 0) {
					q.push(nextNode);
					D[nextNode] = node;
					if (nextNode == end) break;
				}

			}
		}

		if (D[end] == -1) break;

		int flow = INF;
		for (int i = end; i != start; i = D[i]) {
			int pNode = D[i];
			flow = min(flow, C[pNode][i] - F[pNode][i]);
		}

		for (int i = end; i != start; i = D[i]) {
			int pNode = D[i];
			F[pNode][i] += flow;
			F[i][pNode] -= flow;
		}

		answer += flow;
	}
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	char a, b;
	for (int i = 0, c; i < N; i++) {
		scanf(" %c %c %d", &a, &b, &c);
		int start = charToInt(a);
		int end = charToInt(b);
		E[start].push_back(end);
		E[end].push_back(start);
		C[start][end] += c;
		C[end][start] += c;
	}

	maxFlow(0, 25);
	printf("%d", answer);

	return 0;
}