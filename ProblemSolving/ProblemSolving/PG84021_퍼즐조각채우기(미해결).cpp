#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int Y, X;

struct Point {
    int y, x;
};

struct Block {
    int num;
    int row[6];
    int col[6];
    bool used;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
bool check[50][50] = { false, };

vector<Block> gv;
vector<Block> tv;

//bool cmp(Point a, Point b) {
//    if (a.y == b.y)
//        return a.x < b.x;
//    return a.y < b.y;
//}

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
            int nx= front.x + dx[k];

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
    
    vector<Point> tmp;
    int row[6] = { 0, };
    int col[6] = { 0, };
    while (!q2.empty()) {

        Point front = q2.front();
        q2.pop();

        int ny = front.y - min_y;
        int nx = front.x - min_x;

        tmp.push_back({ ny, nx });
        row[ny]++;
        col[nx]++;
    }

    Block newBlock;
    newBlock.num = blockSize;
    memcpy(newBlock.row, row, sizeof(row));
    memcpy(newBlock.col, col, sizeof(col));
    newBlock.used = false;

    if (mode == 1)
        gv.push_back(newBlock);
    else
        tv.push_back(newBlock);
}

bool isSame(Block tBlock, Block gBlock) {

    int row[6] = { 0, };
    int col[6] = { 0, };

    bool flag = true;
    for (int i = 0; i < 6; i++) {
        if (tBlock.row[i] != gBlock.row[i]) {
            flag = false;
            break;
        }

        if (tBlock.col[i] != gBlock.col[i]) {
            flag = false;
            break;
        }
    }

    if (flag)
        return true;


    // 90도 회전
    // 행을 뒤집어서 열에 넣기
    // 열은 그대로 행에 넣기
    for (int i = 0; i < 6; i++) {
        col[i] = tBlock.row[5 - i];
        row[i] = tBlock.col[i];
    }

    for (int i = 0; i < 6; i++) {
        if (row[i] != gBlock.row[i]) {
            flag = false;
            break;
        }

        if (col[i] != gBlock.col[i]) {
            flag = false;
            break;
        }
    }

    if (flag)
        return true;

    // 180도 회전
    // 행을 뒤집어서 행에 넣기
    // 열은 그대로 열에 넣기
    for (int i = 0; i < 6; i++) {
        row[i] = tBlock.row[5 - i];
        col[i] = tBlock.col[i];
    }

    for (int i = 0; i < 6; i++) {
        if (row[i] != gBlock.row[5-i]) {
            flag = false;
            break;
        }

        if (col[i] != gBlock.col[i]) {
            flag = false;
            break;
        }
    }

    if (flag)
        return true;

    // 270도 회전
    // 열을 뒤집어서 행에 넣기
    // 행은 그대로 열에 넣기
    for (int i = 0; i < 6; i++) {
        row[i] = tBlock.col[5 - i];
        col[i] = tBlock.row[i];
    }

    for (int i = 0; i < 6; i++) {
        if (row[i] != gBlock.row[i]) {
            flag = false;
            break;
        }

        if (col[i] != gBlock.col[i]) {
            flag = false;
            break;
        }
    }

    return flag;
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

            if (isSame(tv[t], gv[g])) {
                answer += tv[t].num;
                tv[t].used = true;
                break;
            }

        }
    }

    return answer;
}

int main() {
    cout << solution({ {1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0} },
        { {1,0,0,1,1,0},{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0},{0,1,0,0,0,0} });
    return 0;
}