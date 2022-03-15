#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define NODE_NUM 300001

vector<int> E[NODE_NUM];

void dfs(int parentNode, int curNode, vector<long long> &a, long long &answer) {

    // ������尡 �ƴ϶��
    for (int i = 0; i < E[curNode].size(); i++) {
        int nextNode = E[curNode][i];
        if (nextNode == parentNode) continue;
        dfs(curNode, nextNode, a, answer);
    }

    a[parentNode] += a[curNode];
    answer += abs(a[curNode]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    
    // Ÿ�� ��ȯ
    vector<long long> a_long;

    // ����ġ�� ���� 0���� ����
    long long sum = 0;
    bool isAllZero = true;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        isAllZero = false;
        a_long.push_back(a[i]);
    }
    if (sum != 0) return -1;
    else if (isAllZero) return 0;
    
    for (int i = 0; i < edges.size(); i++) {
        E[edges[i][0]].push_back(edges[i][1]);
        E[edges[i][1]].push_back(edges[i][0]);
    }
    
    // �� ��带 �������� ���� ������ 0���� ������ִ� ���� ����
    long long answer = 0;
    dfs(0, 0, a_long, answer);
    return answer;
}

int main() {

    vector<int> a = { -5, 0, 2, 1, 2 };
    vector<vector<int>> edges = { {0,1}, {3,4}, {2,3}, {0,3} };
    cout << solution(a, edges);

    return 0;
}