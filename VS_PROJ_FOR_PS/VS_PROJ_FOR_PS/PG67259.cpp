#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

struct P {
    int y, x, d;
};

// 상, 좌, 하, 우
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0 , 1 };

int roadKind(P p, P np) {
    if (p.d == np.d)
        return 1;
    else
        return 6;
}

void dfs(P p, int check[30][30], vector<vector<int>> board, int vSize, int &ans) {
    
    // 현재 좌표가 도착지점이면 현재까지의 거리와 정답을 비교 후 갱신
    if (p.y == vSize - 1 && p.x == vSize - 1) {
        if (ans > check[p.y][p.x] - 1)
            ans = check[p.y][p.x] - 1;
    }
    
    int check_bk[30][30];
    memcpy(check_bk, check, sizeof(check));

    // 현재 좌표에서 갈 수 있는 좌표를 구해서 dfs 재귀
    for (int k = 0; k < 4; k++) {
        // 현재 방향과 반대 방향은 제외
        if ((p.d + 2) % 4 == k)
            continue;

        int ny = p.y + dy[k];
        int nx = p.x + dx[k];
        P np = { ny, nx, k };

        // 범위 밖으로 나가면
        if (ny < 0 || ny >= vSize || nx < 0 || nx >= vSize)
            continue;

        if (board[ny][nx] == 1)
            continue;

        // 다음 지점이 직선구간인가 코너구간인가
        int kind = roadKind(p, np);

        // 지금까지의 도로 비용 + 추가되는 도로 + 곡선 도로냐 
        int cost = check[p.y][p.x] + (100 * kind);

        if (check[ny][nx] == 0) {
            check[ny][nx] = cost;
            dfs(np, check, board, board.size(), ans);
            memcpy(check, check_bk, sizeof(check));
        }
    }

}

int solution(vector<vector<int>> board) {

    int answer = 987654321;

    int check[30][30] = { 0, };
    P p = { 0, 0, 2 };
    check[0][0] = 1;
    dfs(p, check, board, board.size(), answer);

    memset(check, 0, sizeof(check));

    p = { 0, 0, 3 };
    check[0][0] = 1;
    dfs(p, check, board, board.size(), answer);

    return answer;
}

int main() {
    vector<vector<int>> board = { 
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0}
    };
    cout << solution(board);


    return 0;
}