// 한 정점에서 다른 모든 정점까지의 거리를 구하고
// 최대 거리값을 가지는 노드 번호를 출력하는 문제

// 미방문한 것 중에 가장 거리가 짧은 노드를 찾을 때 우선순위큐 사용
// 시간복잡도 : O(E*logE) == O(E*logV) (보통, V^2 > E 이므로 우변으로 표기 가능)
/**
* 모든 정점을 방문해서 인접한 정점을 확인하는 작업 ==> 간선의 개수 E 만큼
* 최악의 경우, 모든 인접한 정점을 거쳐가는 비용으로 거리 정보를 업데이트해야함. 이 거리정보를 우선순위큐에 삽입하는 경우 ==> E*logE
* 최악의 경우, pq에 있는 모든 원소를 꺼내봐야함 ==> *logE
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define NODE_NUM 20001
#define INFINITE 99999

struct DIS_INFO {
    int node, dis;
};

vector<int> E[NODE_NUM];
int d[NODE_NUM];        // 다익스트라 알고리즘 사용 시, 노드별 최단 거리 배열
bool visited[NODE_NUM]; // 다익스트라 알고리즘 사용 시, 노드 방문 체크 배열
priority_queue<DIS_INFO, vector<DIS_INFO>> pq;

bool operator<(DIS_INFO a, DIS_INFO b) {
    return a.dis > b.dis;
}

// 미방문이면서 가장 가까운 다음 노드 선택
int getMinDistance(int n) {

    while (!pq.empty()) {
        DIS_INFO top = pq.top();
        pq.pop();

        if (!visited[top.node])
            return top.node;
    }

    return -1;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    // 간선 정보 저장
    for (vector<int>& e : edge) {
        int fromNode = e[0];
        int endNode = e[1];

        E[fromNode].push_back(endNode);
        E[endNode].push_back(fromNode);
    }

    // 최단 거리 배열의 초기값은 무한한 값으로 설정
    for (int i = 1; i <= n; i++)
        d[i] = INFINITE;

    // 시작 노드는 최단 거리가 0으로 설정
    int startNode = 1;
    d[startNode] = 0;
    pq.push({ startNode, d[startNode] });

    for (int i = 0; i < n; i++) {
        // 미방문했으며 거리가 가장 짧은 노드를 다음 방문 노드로 설정
        int nextNode = getMinDistance(n);
        visited[nextNode] = true;

        // nextNode를 기준으로 거리 정보 업데이트
        for (int k = 0; k < E[nextNode].size(); k++) {

            int nextEndNode = E[nextNode][k];

            // 경유해서 가는게 더 최단거리라면 업데이트
            if (d[nextEndNode] > d[nextNode] + 1) {
                d[nextEndNode] = d[nextNode] + 1;
                pq.push({ nextEndNode, d[nextEndNode] });
            }
        }
    }

    int maxVal = -1;
    for (int i = 1; i <= n; i++) {
        if (maxVal < d[i])
            maxVal = d[i];
    }

    for (int i = 1; i <= n; i++) {
        if (maxVal == d[i])
            answer++;
    }

    return answer;
}

int main() {

    int n = 6;
    vector<vector<int>> edge = {
        {3,6},
        {4,3},
        {3,2},
        {1,3},
        {1,2},
        {2,4},
        {5,2}
    };

    cout << solution(n, edge);

    return 0;
}