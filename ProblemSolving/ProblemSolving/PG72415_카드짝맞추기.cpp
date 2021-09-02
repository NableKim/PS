#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define BIG_NUM 9999

struct P {
    int y, x;
};

vector<P> v[7];
vector<int> arr;
vector<vector<int>> map;
int sy, sx, sy_bk, sx_bk, answer = BIG_NUM;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void swap(int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int bfs(P target) {

    int ty, tx;
    ty = target.y;
    tx = target.x;

    queue<P> q;
    q.push({sy, sx});
    
    int check[4][4];
    memset(check, BIG_NUM, sizeof(check));
    check[sy][sx] = 0;

    while (!q.empty()) {

        // 갈 수 있는 다음 위치 구하기
        P front = q.front(); q.pop();

        // 한칸 단위로 움직이는 경우
        int ny, nx;
        for (int k = 0; k < 4; k++) {
            ny = front.y + dy[k];
            nx = front.x + dx[k];

            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
            if (check[ny][nx] < check[front.y][front.x] + 1) continue;

            check[ny][nx] = check[front.y][front.x] + 1;
            q.push({ ny, nx });

            // target을 발견했다면
            if (ty == ny && tx == nx) {
                sy = ty; sx = tx;
                return check[ny][nx];
            }
        }
        
        // ctrl + 방향키
        for (int k = 0; k < 4; k++) {
            int pre_y = front.y;
            int pre_x = front.x;

            // 2~3칸 장거리 이동 가능
            for (int t = 2; t < 4; t++) {
                ny = front.y + dy[k]*t;
                nx = front.x + dx[k]*t;

                // 범위를 벗어난 경우
                if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) break;
                
                pre_y = ny;
                pre_x = nx;

                // 이 방향에 카드가 존재하는 경우
                if (map[ny][nx] != 0)
                    break;
            }

            // 이 방향으로는 움직일 곳이 없으면 제자리
            if (pre_y == front.y && pre_x == front.x)
                continue;

            // 장거리로 움직일 수 있는 곳이 있다면 que에 추가
            if (check[pre_y][pre_x] > check[front.y][front.x] + 1) {
                check[pre_y][pre_x] = check[front.y][front.x] + 1;
                q.push({ pre_y, pre_x });
            }

            // target을 발견했다면
            if (ty == pre_y && tx == pre_x) {
                sy = ty; sx = tx;
                return check[pre_y][pre_x];
            }
        }
    }

    return 0;
}

int minResult(int node) {

    int by = sy, bx = sx;

    int result1 = 0;
    result1 += bfs(v[node][0]);
    result1 += bfs(v[node][1]);

    int ssy = sy, ssx = sx;

    // 처음 위치값 원복
    sy = by; sx = bx;

    int result2 = 0;
    result2 += bfs(v[node][1]);
    result2 += bfs(v[node][0]);

    if (result1 < result2) {
        sy = ssy; sx = ssx;
        return result1;
    }
    return result2;
}

void permu(int depth, int arrSize) {
    if (depth == arrSize) {

        // map 정보 back
        vector<vector<int>> map_bk;
        map_bk = map;
        sy = sy_bk; sx = sx_bk;

        int result = 0;

        // 주어진 순열에 따라 bfs 탐색 시작
        for (int i = 0; i < arrSize; i++) {
            result += minResult(arr[i]);

            map[v[arr[i]][0].y][v[arr[i]][0].x] = 0;
            map[v[arr[i]][1].y][v[arr[i]][1].x] = 0;

            // 이 경우는 더 이상 할 필요 없음
            if (result >= answer) {
                map = map_bk;
                return;
            }
        }

        // 정답 갱신
        if (result < answer)
            answer = result;

        // map 정보 원복
        map = map_bk;

        return;
    }

    for (int i = depth; i < arrSize; i++) {
        swap(i, depth);
        permu(depth + 1, arrSize);
        swap(i, depth);
    }
}

int solution(vector<vector<int>> board, int r, int c) {

    // 주어진 입력으로 어떤 카드들이 뒤집어져 있는지 메모
    vector<int> tmp; 
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[y][x] != 0) {
                v[board[y][x]].push_back({ y, x });
                tmp.push_back(board[y][x]);
            }
        }
    }

    sort(tmp.begin(), tmp.end());

    int pre = tmp[0];
    arr.push_back(pre);
    for (int i = 1; i < tmp.size(); i++) {
        if (pre != tmp[i]) {
            arr.push_back(tmp[i]);
            pre = tmp[i];
        }
    }

    // 시작위치 전역화
    sy_bk = sy = r; sx_bk = sx = c;
    map = board;

    // arr를 가지고 순열 구하기
    permu(0, arr.size());

    return answer+(arr.size()*2);
}

int main() {

    //vector<vector<int>> board = { {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} };
    //vector<vector<int>> board = { {1,0,0,5},{0,0,0,0},{0,0,0,0},{5,0,1,0} };
    //vector<vector<int>> board = { {1,1,6,6},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    vector<vector<int>> board = { {1, 5, 0, 2}, {6, 4, 3, 0}, {0, 2, 1, 5}, {3, 0, 6, 4} };
    int r = 0;
    int c = 0;

    cout << solution(board, r, c);

    return 0;
}