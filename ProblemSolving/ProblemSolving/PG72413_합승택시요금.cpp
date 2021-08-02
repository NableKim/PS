#include <cstdio>
#include <vector>
#define MAX_COST 20000001
using namespace std;

int C[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    // ������� �ʱ�ȭ
    for (int start = 1; start <= n; start++) {
        for (int end = 1; end <= n; end++) {
            if (start == end) continue;
            C[start][end] = MAX_COST;
        }
    }

    // ���� ���� �޸�
    for (vector<int>& v : fares)
        C[v[0]][v[1]] = C[v[1]][v[0]] = v[2];

    // �÷��̵� �ͼ� �˰���
    for (int k = 1; k <= n; k++) {
        for (int start = 1; start <= n; start++)
        {
            if (k == start) continue;
            for (int end = 1; end <= n; end++)
            {
                if (start == end) continue;
                C[start][end] = C[start][end] > C[start][k] + C[k][end] ? C[start][k] + C[k][end] : C[start][end];
            }
        }
    }

    // ������ �ϳ��� ��� ��� ����ϱ�
    answer = C[s][a] + C[s][b];
    for (int k = 1; k <= n; k++) {
        int sum = C[s][k] + C[k][a] + C[k][b];
        answer = sum < answer ? sum : answer;
    }

    return answer;
}

int main() {

    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;
    vector<vector<int>> fares = { {4, 1, 10}, { 3, 5, 24 }, { 5, 6, 2 }, { 3, 1, 41 }, { 5, 1, 24 }, { 4, 6, 50 }, { 2, 4, 66 }, { 2, 3, 22 }, { 1, 6, 25 } };

    printf("%d", solution(n, s, a, b, fares));

	return 0;
}