// �� �������� �ٸ� ��� ���������� �Ÿ��� ���ϰ�
// �ִ� �Ÿ����� ������ ��� ��ȣ�� ����ϴ� ����

// �̹湮�� �� �߿� ���� �Ÿ��� ª�� ��带 ã�� �� ����Ž�� ���
// �ð����⵵ : O(V^2 + E)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NODE_NUM 20001
#define INFINITE 99999

vector<int> E[NODE_NUM];
int d[NODE_NUM];        // ���ͽ�Ʈ�� �˰��� ��� ��, ��庰 �ִ� �Ÿ� �迭
bool visited[NODE_NUM]; // ���ͽ�Ʈ�� �˰��� ��� ��, ��� �湮 üũ �迭

// �̹湮�̸鼭 ���� ����� ���� ��� ����
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

    for (int i = 0; i < n; i++) {
        // �̹湮������ �Ÿ��� ���� ª�� ��带 ���� �湮 ���� ����
        int nextNode = getMinDistance(n);
        visited[nextNode] = true;

        // nextNode�� �������� �Ÿ� ���� ������Ʈ
        for (int k = 0; k < E[nextNode].size(); k++) {

            int nextEndNode = E[nextNode][k];

            // �����ؼ� ���°� �� �ִܰŸ���� ������Ʈ
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