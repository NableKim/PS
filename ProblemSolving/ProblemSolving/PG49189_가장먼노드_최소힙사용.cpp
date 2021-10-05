// �� �������� �ٸ� ��� ���������� �Ÿ��� ���ϰ�
// �ִ� �Ÿ����� ������ ��� ��ȣ�� ����ϴ� ����

// �̹湮�� �� �߿� ���� �Ÿ��� ª�� ��带 ã�� �� �켱����ť ���
// �ð����⵵ : O(E*logE) == O(E*logV) (����, V^2 > E �̹Ƿ� �캯���� ǥ�� ����)
/**
* ��� ������ �湮�ؼ� ������ ������ Ȯ���ϴ� �۾� ==> ������ ���� E ��ŭ
* �־��� ���, ��� ������ ������ ���İ��� ������� �Ÿ� ������ ������Ʈ�ؾ���. �� �Ÿ������� �켱����ť�� �����ϴ� ��� ==> E*logE
* �־��� ���, pq�� �ִ� ��� ���Ҹ� ���������� ==> *logE
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
int d[NODE_NUM];        // ���ͽ�Ʈ�� �˰��� ��� ��, ��庰 �ִ� �Ÿ� �迭
bool visited[NODE_NUM]; // ���ͽ�Ʈ�� �˰��� ��� ��, ��� �湮 üũ �迭
priority_queue<DIS_INFO, vector<DIS_INFO>> pq;

bool operator<(DIS_INFO a, DIS_INFO b) {
    return a.dis > b.dis;
}

// �̹湮�̸鼭 ���� ����� ���� ��� ����
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

    // ���� ���� ����
    for (vector<int>& e : edge) {
        int fromNode = e[0];
        int endNode = e[1];

        E[fromNode].push_back(endNode);
        E[endNode].push_back(fromNode);
    }

    // �ִ� �Ÿ� �迭�� �ʱⰪ�� ������ ������ ����
    for (int i = 1; i <= n; i++)
        d[i] = INFINITE;

    // ���� ���� �ִ� �Ÿ��� 0���� ����
    int startNode = 1;
    d[startNode] = 0;
    pq.push({ startNode, d[startNode] });

    for (int i = 0; i < n; i++) {
        // �̹湮������ �Ÿ��� ���� ª�� ��带 ���� �湮 ���� ����
        int nextNode = getMinDistance(n);
        visited[nextNode] = true;

        // nextNode�� �������� �Ÿ� ���� ������Ʈ
        for (int k = 0; k < E[nextNode].size(); k++) {

            int nextEndNode = E[nextNode][k];

            // �����ؼ� ���°� �� �ִܰŸ���� ������Ʈ
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