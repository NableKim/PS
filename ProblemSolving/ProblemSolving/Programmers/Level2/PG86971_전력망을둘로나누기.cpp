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

    // ���� ���� ���
    for (int i = 0; i < wires.size(); i++) {

        int n1 = wires[i][0];
        int n2 = wires[i][1];

        E[n1][n2] = true;
        E[n2][n1] = true;
    }

    // ���� n-1���� ���� �� �ϳ��� ����
    for (int i = 0; i < wires.size(); i++) {

        int n1 = wires[i][0];
        int n2 = wires[i][1];

        E[n1][n2] = false;
        E[n2][n1] = false;

        // ���� ���� ������ ������ bfs Ž�� >> �湮 ���� ���
        bool visited[NODE_NUM] = { false, };
        vector<int> v;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                v.push_back(bfs(j, visited, n));
            }
        }

        // �� ������ ���� ���̸� ������Ʈ
        int diff = v[0] - v[1];
        if (diff < 0)
            diff *= -1;

        answer = answer > diff ? diff : answer;

        E[n1][n2] = true;
        E[n2][n1] = true;
    }
    
    // ���� ���
    return answer;
}

int main() {

    int n = 9;
    vector<vector<int>> wires= { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };

    cout << solution(n, wires);

    return 0;
}