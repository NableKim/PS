#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool map[12][12];

void check(int y, int x, int n) {

    // 왼쪽 위
    int ny = y, nx = x;
    while (1) {
        ny -= 1;
        nx -= 1;
        if (ny < 0 || nx < 0) break;
        map[ny][nx] = true;
    }

    // 오른쪽 위
    ny = y, nx = x;
    while (1) {
        ny -= 1;
        nx += 1;
        if (ny < 0 || nx >= n) break;
        map[ny][nx] = true;
    }

    // 왼쪽 아래
    ny = y, nx = x;
    while (1) {
        ny += 1;
        nx -= 1;
        if (ny >= n || nx < 0) break;
        map[ny][nx] = true;
    }

    // 오른쪽 아래
    ny = y, nx = x;
    while (1) {
        ny += 1;
        nx += 1;
        if (ny >= n || nx >= n) break;
        map[ny][nx] = true;
    }

    // 위
    ny = y, nx = x;
    while (1) {
        ny -= 1;
        if (ny < 0) break;
        map[ny][nx] = true;
    }

    // 아래
    ny = y, nx = x;
    while (1) {
        ny += 1;
        if (ny >= n) break;
        map[ny][nx] = true;
    }

    // 왼쪽
    ny = y, nx = x;
    while (1) {
        nx -= 1;
        if (nx < 0) break;
        map[ny][nx] = true;
    }

    // 오른쪽
    ny = y, nx = x;
    while (1) {
        nx += 1;
        if (nx >= n) break;
        map[ny][nx] = true;
    }
}

void dfs(int depth, int* ptr_answer, int n) {

    // n개의 퀸을 모두 배치한 경우
    if (depth == n) {
        (*ptr_answer)++;
        return;
    }

    // map 백업
    bool map_bk[12][12];
    memcpy(map_bk, map, sizeof(map));

    // depth행에서 i번째 열에 퀸 놓기
    for (int i = 0; i < n; i++) {

        // 퀸을 놓을 수 없다면 스킵
        if (map[depth][i]) continue;

        // i번째 열에 퀸 놓고 퀸의 영향력 표시 후 dfs 실행. 다 수행 후 map 복구
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