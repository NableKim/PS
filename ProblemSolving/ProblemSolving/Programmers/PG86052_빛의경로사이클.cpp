/*
dfs를 이용한 사이클 찾기
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define LENGTH 500

bool check[LENGTH][LENGTH][4];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
vector<string> gGrid;
vector<int> answer;
int sy, sx, sk;
int Y, X;

void dfs(int y, int x, int k, int depth) {

    check[y][x][k] = true;

    int ny = y + dy[k];
    int nx = x + dx[k];

    if (ny < 0)
        ny = Y - 1;
    else if (ny >= Y)
        ny = 0;

    if (nx < 0)
        nx = X - 1;
    else if (nx >= X)
        nx = 0;

    int nk;
    if (gGrid[ny][nx] == 'L') {
        nk = (k + 1) % 4;
    }
    else if (gGrid[ny][nx] == 'R') {
        nk = (k + 3) % 4;
    }
    else {
        nk = k;
    }

    if (check[ny][nx][nk]) {
        if (sy == ny && sx == nx && sk == nk)
            answer.push_back(depth+1);
    }
    else 
        dfs(ny, nx, nk, depth+1);
}

vector<int> solution(vector<string> grid) {
    
    
    Y = grid.size();
    X = grid[0].size();
    gGrid = grid;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            for (int k = 0; k < 4; k++) {
                if (!check[y][x][k]) {
                    //check[y][x][k] = true;
                    sy = y;
                    sx = x;
                    sk = k;
                    dfs(y, x, k, 0);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {

    /*vector<int> v = solution({
        "SL",
        "LR"
        });*/


    vector<int> v = solution({
        "R", 
        "R"
        });

    for (int& a : v)
        cout << a << " " << endl;



    return 0;
}