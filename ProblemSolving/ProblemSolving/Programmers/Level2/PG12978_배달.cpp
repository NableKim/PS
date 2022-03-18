#include <iostream>
#include <vector>
using namespace std;

#define MAX_NODE 51
#define INF 1e9

struct INFO {
    int node, cost;
};

vector<INFO> v[MAX_NODE];
bool visited[MAX_NODE];
int D[MAX_NODE];

int getMinDistanceNode(int N) {
    int minDis = INF;
    int minNode = 0;
    for (int i = 1; i <= N; i++) {
        if (minDis > D[i] && !visited[i]) {
            minDis = D[i];
            minNode = i;
        }
    }
    return minNode;
}

void dijkstra(int N) {

    int cnt = 0;
    while (cnt < N) {
        // D에서 아직 미방문이면서 가장 가까운 노드 찾기
        int node = getMinDistanceNode(N);

        // 방문 처리
        visited[node] = true;
        cnt++;

        for (int i = 0; i < v[node].size(); i++) {
            int endNode = v[node][i].node;
            int endCost = v[node][i].cost;
            D[endNode] = D[endNode] > (D[node] + endCost) ? (D[node] + endCost) : D[endNode];
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // 다익스트라로 1번 정점을 기준으로 각 정점까지의 최단 거리 구하기

    // 간선 정보 저장
    for (int i = 0; i < road.size(); i++) {
        int start = road[i][0];
        int end = road[i][1];
        int cost = road[i][2];

        v[start].push_back({ end, cost });
        v[end].push_back({ start, cost });
    }

    for (int i = 1; i <= N; i++)
        D[i] = INF;

    D[1] = 0;

    dijkstra(N);

    // D배열에서 K 이하인 마을의 개수 리턴
    for (int i = 1; i <= N; i++) {
        if (D[i] <= K) answer++;
    }

    return answer;
}