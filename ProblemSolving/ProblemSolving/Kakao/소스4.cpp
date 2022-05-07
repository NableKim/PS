#include <iostream>

// 등산 코스를 짜야하는데 주어진 노드는 출입구, 일반지점, 산봉우리(정상)으로 나뉨
// 등산 코스는 출입구를 시작으로 한 군데 정상을 찍고 동일한 출입구로 나와야한다.
// 이 등산코스에서 가장 비용이 큰 등산로(노드와 노드간 거리=간선)가 그 등산코스의 강도이다.
// 등산 강도가 가장 작은 등산 코스를 짠다고 할때 최소 강도는 얼마인가

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

		// 산봉우리 노드를 만난 경우
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

			// 출입구라면
			if (isGate[nextNode])
				continue;

			// 이미 구한 정답보다도 강도가 높다면
			if (nextCost > answerCandidate[1])
				continue;

			// 이미 더 낮은 강도로 지나간 경우라면
			if (visited[nextNode] <= nextCost)
				continue;

			visited[nextNode] = nextCost;
			q.push({ nextNode, nextCost });
		}

	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	

	// 간선 정보 메모
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
