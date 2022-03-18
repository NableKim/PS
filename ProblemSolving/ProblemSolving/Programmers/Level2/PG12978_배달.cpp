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
        // D���� ���� �̹湮�̸鼭 ���� ����� ��� ã��
        int node = getMinDistanceNode(N);

        // �湮 ó��
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

    // ���ͽ�Ʈ��� 1�� ������ �������� �� ���������� �ִ� �Ÿ� ���ϱ�

    // ���� ���� ����
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

    // D�迭���� K ������ ������ ���� ����
    for (int i = 1; i <= N; i++) {
        if (D[i] <= K) answer++;
    }

    return answer;
}