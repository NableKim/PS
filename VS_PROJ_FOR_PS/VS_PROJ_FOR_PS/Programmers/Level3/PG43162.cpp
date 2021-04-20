#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> computers, bool* visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // 현재 노드에서 방문할 수 있는 노드를 큐에 추가
        for (int k = 0; k < computers.size(); k++) {
            if (k == start)
                continue;

            if (computers[front][k] && !visited[k]) {
                visited[k] = true;
                q.push(k);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    //인접행렬이 만들어진거니까
    bool visited[200] = { false, };
    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            bfs(i, computers, visited);
            answer++;
        }
    }
    return answer;
}

int main() {
    int n =3;
    vector<vector<int>> computers = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
    
    cout << solution(3, computers);

    return 0;
}