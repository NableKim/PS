#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int Y, X;

struct Point {
    int y, x;
};

struct Block {
    int num;
    vector<Point> v;
    bool used;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
bool check[50][50] = { false, };

vector<Block> gv;
vector<Block> tv;

bool cmp(Point a, Point b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

void bfs(vector<vector<int>> map, int y, int x, int mode) {

    queue<Point> q, q2;

    q.push({ y, x });
    q2.push({ y, x });
    check[y][x] = true;

    while (!q.empty()) {

        Point front = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = front.y + dy[k];
            int nx = front.x + dx[k];

            if (ny < 0 || ny >= Y || nx < 0 || nx >= X)
                continue;

            if (map[ny][nx] == mode || check[ny][nx])
                continue;

            check[ny][nx] = true;
            q.push({ ny, nx });
            q2.push({ ny, nx });
        }
    }

    int blockSize = q2.size();

    int min_y, min_x;
    min_y = min_x = 100;

    // y, x 최소값 구하기
    for (int i = 0; i < blockSize; i++) {

        Point front = q2.front();
        q2.pop();

        if (min_y > front.y)
            min_y = front.y;

        if (min_x > front.x)
            min_x = front.x;

        q2.push(front);
    }

    Block newBlock;
    newBlock.num = blockSize;
    newBlock.used = false;
    while (!q2.empty()) {
        Point front = q2.front();
        q2.pop();
        newBlock.v.push_back(front);
    }

    if (mode == 1)
        gv.push_back(newBlock);
    else
        tv.push_back(newBlock);
}

bool compare(vector<Point> v1, vector<Point> v2) {
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i].y != v2[i].y
            || v1[i].x != v2[i].x)
            return false;
    }
    return true;
}

bool isSame(Block tBlock, Block gBlock, int limit) {

    int bSize = tBlock.num;
    bool flag = true;

    vector<Point> v1, v2;
    
    // v1 만들기
    int v1_min_y=100, v1_min_x=100;
    for (int i = 0; i < bSize; i++) {
        if (v1_min_y > gBlock.v[i].y)
            v1_min_y = gBlock.v[i].y;
        if (v1_min_x > gBlock.v[i].x)
            v1_min_x = gBlock.v[i].x;
    }

    for (int i = 0; i < bSize; i++)
        v1.push_back({ gBlock.v[i].y - v1_min_y, gBlock.v[i].x - v1_min_x });
    sort(v1.begin(), v1.end(), cmp);

    // 0도
    int v2_min_y = 100, v2_min_x = 100;
    for (int i = 0; i < bSize; i++) {
        if (v2_min_y > tBlock.v[i].y)
            v2_min_y = tBlock.v[i].y;
        if (v2_min_x > tBlock.v[i].x)
            v2_min_x = tBlock.v[i].x;
    }

    for (int i = 0; i < bSize; i++)
        v2.push_back({ tBlock.v[i].y - v2_min_y, tBlock.v[i].x - v2_min_x });

    sort(v2.begin(), v2.end(), cmp);
    bool result = compare(v1, v2);
    if (result) return true;

    // 90도
    v2.clear();
    vector<Point> tmp;
    for (int i = 0; i < bSize; i++) {
        tmp.push_back({ tBlock.v[i].x, limit - tBlock.v[i].y });
    }

    v2_min_y = 100, v2_min_x = 100;
    for (int i = 0; i < bSize; i++) {
        if (v2_min_y > tmp[i].y)
            v2_min_y = tmp[i].y;
        if (v2_min_x > tmp[i].x)
            v2_min_x = tmp[i].x;
    }

    for (int i = 0; i < bSize; i++)
        v2.push_back({ tmp[i].y - v2_min_y, tmp[i].x - v2_min_x });

    sort(v2.begin(), v2.end(), cmp);
    result = compare(v1, v2);
    if (result) return true;

    // 180도
    v2.clear();
    tmp.clear();
    for (int i = 0; i < bSize; i++) {
        tmp.push_back({ limit - tBlock.v[i].y, tBlock.v[i].x });
    }

    v2_min_y = 100, v2_min_x = 100;
    for (int i = 0; i < bSize; i++) {
        if (v2_min_y > tmp[i].y)
            v2_min_y = tmp[i].y;
        if (v2_min_x > tmp[i].x)
            v2_min_x = tmp[i].x;
    }

    for (int i = 0; i < bSize; i++)
        v2.push_back({ tmp[i].y - v2_min_y, tmp[i].x - v2_min_x });

    sort(v2.begin(), v2.end(), cmp);
    result = compare(v1, v2);
    if (result) return true;

    // 270도
    v2.clear();
    tmp.clear();
    for (int i = 0; i < bSize; i++) {
        tmp.push_back({ limit - tBlock.v[i].x, tBlock.v[i].y });
    }

    v2_min_y = 100, v2_min_x = 100;
    for (int i = 0; i < bSize; i++) {
        if (v2_min_y > tmp[i].y)
            v2_min_y = tmp[i].y;
        if (v2_min_x > tmp[i].x)
            v2_min_x = tmp[i].x;
    }

    for (int i = 0; i < bSize; i++)
        v2.push_back({ tmp[i].y - v2_min_y, tmp[i].x - v2_min_x });

    sort(v2.begin(), v2.end(), cmp);
    result = compare(v1, v2);
    if (result) return true;
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;


    Y = game_board.size();
    X = game_board[0].size();

    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (!check[y][x] && game_board[y][x] == 0)
                bfs(game_board, y, x, 1);
        }
    }

    memset(check, false, sizeof(check));
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (!check[y][x] && table[y][x] == 1)
                bfs(table, y, x, 0);
        }
    }

    int tBlockSize = tv.size();
    int gBlockSize = gv.size();
    for (int g = 0; g < gBlockSize; g++) {
        for (int t = 0; t < tBlockSize; t++) {
            if (tv[t].num != gv[g].num) continue;
            if (tv[t].used) continue;

            if (isSame(tv[t], gv[g], X-1)) {
                answer += tv[t].num;
                tv[t].used = true;
                break;
            }

        }
    }

    return answer;
}

int main() {
    cout << solution(
        { {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0} },
        { {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1} }
    );
    /*cout << solution(
        {
            { 0, 0, 1 }, 
            { 1, 0, 1 }, 
            { 1, 0, 0 }
        },
        {
            { 0, 0, 1 }, 
            { 1, 1, 1 }, 
            { 1, 0, 1 }
        }
    );*/
    /*cout << solution(
        {
            { 0,0,0 }, {1, 1, 0}, { 1,1,1 }
        },
        {
            { 1,1,1 }, {1, 0, 0}, { 0,0,0 }
        }
        );*/
    /*cout << solution({ {1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0} },
        { {1,0,0,1,1,0},{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0},{0,1,0,0,0,0} });*/
    return 0;
}