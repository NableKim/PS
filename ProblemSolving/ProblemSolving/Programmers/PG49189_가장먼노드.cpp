// 한 정점에서 다른 모든 정점까지의 거리를 구하고
// 최대 거리값을 가지는 노드 번호를 출력하는 문제

// 미방문한 것 중에 가장 거리가 짧은 노드를 찾을 때 선형탐색 사용
// 시간복잡도 : O(V^2 + E)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NODE_NUM 20001
#define INFINITE 99999

vector<int> E[NODE_NUM];
int d[NODE_NUM];        // 다익스트라 알고리즘 사용 시, 노드별 최단 거리 배열
bool visited[NODE_NUM]; // 다익스트라 알고리즘 사용 시, 노드 방문 체크 배열

// 미방문이면서 가장 가까운 다음 노드 선택
int getMinDistance(int n) {
    int minVal = INFINITE;
    int minNode = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && minVal > d[i]) {
            minVal = d[i];
            minNode = i;
        }
    }
    return minNode;
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

    for (int i = 0; i < n; i++) {
        // 미방문했으며 거리가 가장 짧은 노드를 다음 방문 노드로 설정
        int nextNode = getMinDistance(n);
        visited[nextNode] = true;

        // nextNode를 기준으로 거리 정보 업데이트
        for (int k = 0; k < E[nextNode].size(); k++) {

            int nextEndNode = E[nextNode][k];

            // 경유해서 가는게 더 최단거리라면 업데이트
            if (d[nextEndNode] > d[nextNode] + 1)
                d[nextEndNode] = d[nextNode] + 1;
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