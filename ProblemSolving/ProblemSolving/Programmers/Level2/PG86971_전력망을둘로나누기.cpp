#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NODE_NUM 101

bool E[NODE_NUM][NODE_NUM];

int bfs(int startNode, bool *visited, int nodeNum) {

    visited[startNode] = true;
    queue<int> q;
    q.push(startNode);
    int cnt = 1;

    while (!q.empty()) {
        int front = q.front(); q.pop();

        for (int k = 1; k <= nodeNum; k++) {
            if (E[front][k] && !visited[k]) {
                q.push(k);
                visited[k] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = NODE_NUM;

    // 간선 정보 기록
    for (int i = 0; i < wires.size(); i++) {

        int n1 = wires[i][0];
        int n2 = wires[i][1];

        E[n1][n2] = true;
        E[n2][n1] = true;
    }

    // 없앨 n-1개의 간선 중 하나를 선택
    for (int i = 0; i < wires.size(); i++) {

        int n1 = wires[i][0];
        int n2 = wires[i][1];

        E[n1][n2] = false;
        E[n2][n1] = false;

        // 없앤 간선 정보를 가지고 bfs 탐색 >> 방문 노드수 계산
        bool visited[NODE_NUM] = { false, };
        vector<int> v;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                v.push_back(bfs(j, visited, n));
            }
        }

        // 두 집합의 노드수 차이를 업데이트
        int diff = v[0] - v[1];
        if (diff < 0)
            diff *= -1;

        answer = answer > diff ? diff : answer;

        E[n1][n2] = true;
        E[n2][n1] = true;
    }
    
    // 정답 출력
    return answer;
}

int main() {

    int n = 9;
    vector<vector<int>> wires= { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };

    cout << solution(n, wires);

    return 0;
}