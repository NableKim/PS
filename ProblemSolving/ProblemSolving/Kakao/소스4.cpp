#include <iostream>

// ��� �ڽ��� ¥���ϴµ� �־��� ���� ���Ա�, �Ϲ�����, ����츮(����)���� ����
// ��� �ڽ��� ���Ա��� �������� �� ���� ������ ��� ������ ���Ա��� ���;��Ѵ�.
// �� ����ڽ����� ���� ����� ū ����(���� ��尣 �Ÿ�=����)�� �� ����ڽ��� �����̴�.
// ��� ������ ���� ���� ��� �ڽ��� §�ٰ� �Ҷ� �ּ� ������ ���ΰ�

#include <string>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NODE 50001
#define MAX_COST 10000001

struct Edge {
	int node, cost;
};

vector<Edge> edges[MAX_NODE];
vector<int> answerCandidate = { MAX_NODE, MAX_COST };
bool isSummit[MAX_NODE];
bool isGate[MAX_NODE];
int visited[MAX_NODE];

void bfs(int startNode) {

	for (int i = 0; i < MAX_NODE; i++)
		visited[i] = MAX_COST;

	visited[startNode] = 0;

	queue<Edge> q;
	q.push({ startNode, 0 });

	while (!q.empty()) {

		Edge front = q.front();
		q.pop();

		// ����츮 ��带 ���� ���
		if (isSummit[front.node]) {
			if (answerCandidate[1] >= front.cost) {
				if(answerCandidate[1] == front.cost &&
					answerCandidate[0] < front.node)
					continue;

				answerCandidate.clear();
				answerCandidate = { front.node, front.cost };
			}
			continue;
		}

		for (int i = 0; i < edges[front.node].size(); i++) {

			int nextNode = edges[front.node][i].node;
			int nextCost = edges[front.node][i].cost < front.cost? front.cost: edges[front.node][i].cost;

			// ���Ա����
			if (isGate[nextNode])
				continue;

			// �̹� ���� ���亸�ٵ� ������ ���ٸ�
			if (nextCost > answerCandidate[1])
				continue;

			// �̹� �� ���� ������ ������ �����
			if (visited[nextNode] <= nextCost)
				continue;

			visited[nextNode] = nextCost;
			q.push({ nextNode, nextCost });
		}

	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	

	// ���� ���� �޸�
	for (int i = 0; i < paths.size(); i++) {
		int node1 = paths[i][0];
		int node2 = paths[i][1];
		int cost = paths[i][2];
		
		edges[node1].push_back({ node2, cost });
		edges[node2].push_back({ node1, cost });
	}

	for (int i = 0; i < gates.size(); i++)
		isGate[gates[i]] = true;

	for (int i = 0; i < summits.size(); i++)
		isSummit[summits[i]] = true;

	for (int i = 0; i < gates.size(); i++) {	
		bfs(gates[i]);
	}

	vector<int> answer = answerCandidate;
	return answer;
}



int main() {

	int n=6;
	vector<vector<int>> paths= { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} };
	vector<int> gates = { 1,3 };
	vector<int> summits = { 5 };

	vector<int> answers = solution(n, paths, gates, summits);
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;

	return 0;
}
