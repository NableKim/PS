#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool map[12][12];

void check(int y, int x, int n) {

    // ���� ��
    int ny = y, nx = x;
    while (1) {
        ny -= 1;
        nx -= 1;
        if (ny < 0 || nx < 0) break;
        map[ny][nx] = true;
    }

    // ������ ��
    ny = y, nx = x;
    while (1) {
        ny -= 1;
        nx += 1;
        if (ny < 0 || nx >= n) break;
        map[ny][nx] = true;
    }

    // ���� �Ʒ�
    ny = y, nx = x;
    while (1) {
        ny += 1;
        nx -= 1;
        if (ny >= n || nx < 0) break;
        map[ny][nx] = true;
    }

    // ������ �Ʒ�
    ny = y, nx = x;
    while (1) {
        ny += 1;
        nx += 1;
        if (ny >= n || nx >= n) break;
        map[ny][nx] = true;
    }

    // ��
    ny = y, nx = x;
    while (1) {
        ny -= 1;
        if (ny < 0) break;
        map[ny][nx] = true;
    }

    // �Ʒ�
    ny = y, nx = x;
    while (1) {
        ny += 1;
        if (ny >= n) break;
        map[ny][nx] = true;
    }

    // ����
    ny = y, nx = x;
    while (1) {
        nx -= 1;
        if (nx < 0) break;
        map[ny][nx] = true;
    }

    // ������
    ny = y, nx = x;
    while (1) {
        nx += 1;
        if (nx >= n) break;
        map[ny][nx] = true;
    }
}

void dfs(int depth, int* ptr_answer, int n) {

    // n���� ���� ��� ��ġ�� ���
    if (depth == n) {
        (*ptr_answer)++;
        return;
    }

    // map ���
    bool map_bk[12][12];
    memcpy(map_bk, map, sizeof(map));

    // depth�࿡�� i��° ���� �� ����
    for (int i = 0; i < n; i++) {

        // ���� ���� �� ���ٸ� ��ŵ
        if (map[depth][i]) continue;

        // i��° ���� �� ���� ���� ����� ǥ�� �� dfs ����. �� ���� �� map ����
        map[depth][i] = true;
        check(depth, i, n);
        dfs(depth + 1, ptr_answer, n);
        memcpy(map, map_bk, sizeof(map));
    }
}

int solution(int n) {
    int answer = 0;
    dfs(0, &answer, n);
    return answer;
}