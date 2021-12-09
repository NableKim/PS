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

        // �� �� �ִ� ���� ��ġ ���ϱ�
        P front = q.front(); q.pop();

        // ��ĭ ������ �����̴� ���
        int ny, nx;
        for (int k = 0; k < 4; k++) {
            ny = front.y + dy[k];
            nx = front.x + dx[k];

            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
            if (check[ny][nx] < check[front.y][front.x] + 1) continue;

            check[ny][nx] = check[front.y][front.x] + 1;
            q.push({ ny, nx });

            // target�� �߰��ߴٸ�
            if (ty == ny && tx == nx) {
                sy = ty; sx = tx;
                return check[ny][nx];
            }
        }
        
        // ctrl + ����Ű
        for (int k = 0; k < 4; k++) {
            int pre_y = front.y;
            int pre_x = front.x;

            // 2~3ĭ ��Ÿ� �̵� ����
            for (int t = 2; t < 4; t++) {
                ny = front.y + dy[k]*t;
                nx = front.x + dx[k]*t;

                // ������ ��� ���
                if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) break;
                
                pre_y = ny;
                pre_x = nx;

                // �� ���⿡ ī�尡 �����ϴ� ���
                if (map[ny][nx] != 0)
                    break;
            }

            // �� �������δ� ������ ���� ������ ���ڸ�
            if (pre_y == front.y && pre_x == front.x)
                continue;

            // ��Ÿ��� ������ �� �ִ� ���� �ִٸ� que�� �߰�
            if (check[pre_y][pre_x] > check[front.y][front.x] + 1) {
                check[pre_y][pre_x] = check[front.y][front.x] + 1;
                q.push({ pre_y, pre_x });
            }

            // target�� �߰��ߴٸ�
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

    // ó�� ��ġ�� ����
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

        // map ���� back
        vector<vector<int>> map_bk;
        map_bk = map;
        sy = sy_bk; sx = sx_bk;

        int result = 0;

        // �־��� ������ ���� bfs Ž�� ����
        for (int i = 0; i < arrSize; i++) {
            result += minResult(arr[i]);

            map[v[arr[i]][0].y][v[arr[i]][0].x] = 0;
            map[v[arr[i]][1].y][v[arr[i]][1].x] = 0;

            // �� ���� �� �̻� �� �ʿ� ����
            if (result >= answer) {
                map = map_bk;
                return;
            }
        }

        // ���� ����
        if (result < answer)
            answer = result;

        // map ���� ����
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

    // �־��� �Է����� � ī����� �������� �ִ��� �޸�
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

    // ������ġ ����ȭ
    sy_bk = sy = r; sx_bk = sx = c;
    map = board;

    // arr�� ������ ���� ���ϱ�
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