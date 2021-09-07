/*
* 시간복잡도 : O(M+N^2), M은 build_frame 크기, N은 주어진 벽면의 길이
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_LEN 101

int PLATE[MAX_LEN][MAX_LEN];
int BAR[MAX_LEN][MAX_LEN];
int L;  // 맵 한 변의 길이

// N x N 크기의 맵 안의 좌표인가
bool range(int y, int x) {
    if (y<0 || y>L || x<0 || x>L)
        return false;
    return true;
}

// 기둥을 세울 수 있는가
bool canInstallBar(int y, int x) {

    // 맨 윗 줄이라면
    if (y == L)
        return false;

    // 바닥이라면
    if (y == 0)
        return true;
    
    // 보의 한쪽 끝에 세우는 건가
    if ((range(y, x-1) && PLATE[y][x - 1]) || PLATE[y][x])
        return true;

    // 다른 기둥 위에 세우는 건가
    if (range(y - 1, x) && BAR[y - 1][x])
        return true;

    return false;
}

// 보를 설치할 수 있는가
bool canInstallBo(int y, int x) {

    // 바닥이거나 오른쪽 끝이라면
    if (y == 0 || x == L)
        return false;

    // 둘 중에 하나라도 기둥이 있다면
    if ((range(y-1, x) && BAR[y-1][x]) || (range(y - 1, x+1) && BAR[y-1][x + 1]))
        return true;

    // 양 쪽에 보가 위치한다면
    if ((range(y, x-1) && PLATE[y][x-1]) && (range(y, x+1) && PLATE[y][x+1]))
        return true;

    return false;
}

bool IsBoStable(int y, int x) {
    return canInstallBo(y, x);
}

bool IsBarStable(int y, int x) {
    return canInstallBar(y, x);
}

// 기둥을 삭제할 수 있는가
bool canDeleteBar(int y, int x) {

    // 좌측 상단 보가 괜찮은가
    if (range(y + 1, x - 1) && PLATE[y + 1][x - 1]) {
        if (!IsBoStable(y + 1, x - 1))
            return false;
    }

    // 우측 상단 보가 괜찮은가
    if (range(y + 1, x) && PLATE[y + 1][x]) {
        if (!IsBoStable(y + 1, x))
            return false;
    }

    // 상단 기둥이 괜찮은가
    if (range(y + 1, x) && BAR[y + 1][x]) {
        if (!IsBarStable(y + 1, x))
            return false;
    }
    
    return true;
}

// 보를 제거할 수 있는가
bool canDeleteBo(int y, int x) {

    // 좌측 보가 괜찮은가
    if (range(y, x - 1) && PLATE[y][x - 1]) {
        if (!IsBoStable(y, x - 1))
            return false;
    }

    // 우측 보가 괜찮은가
    if (range(y, x+1) && PLATE[y][x+1]) {
        if (!IsBoStable(y, x+1))
            return false;
    }

    //// 좌측 하단 기둥이 괜찮은가
    //if (range(y-1, x) && BAR[y-1][x]) {
    //    if (!IsBarStable(y - 1, x))
    //        return false;
    //}

    //// 우측 하단 기둥이 괜찮은가
    //if (range(y - 1, x + 1) && BAR[y - 1][x + 1]) {
    //    if (!IsBarStable(y - 1, x + 1))
    //        return false;
    //}

    // 좌측 상단 기둥이 괜찮은가
    if (range(y, x) && BAR[y][x]) {
        if (!IsBarStable(y, x))
            return false;
    }

    // 우측 상단 기둥이 괜찮은가
    if (range(y, x+1) && BAR[y][x+1]) {
        if (!IsBarStable(y, x+1))
            return false;
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    L = n;

    int y, x, a, b;
    for (vector<int>& v : build_frame) {                      // O(M)
        x = v[0];
        y = v[1];
        a = v[2];
        b = v[3];

        if (a == 0) {   // 기둥 이라면

            // y,x 위치에 기둥을 세울 수 있다면
            if(b==1 && canInstallBar(y, x))
                BAR[y][x] = 1;

            // y,x 위치에 기둥을 제거할 수 있다면
            else if (b == 0) {
                BAR[y][x] = 0;  // y,x 위치에 기둥을 우선 제거
                if (!canDeleteBar(y, x))
                    BAR[y][x] = 1;
            }

        }
        else {  // 보 라면

            // y,x 위치에 보를 세울 수 있다면
            if (b == 1 && canInstallBo(y, x))
                PLATE[y][x] = 1;

            // y,x 위치에 보를 제거할 수 있다면
            else if (b == 0) {
                PLATE[y][x] = 0;  // y,x 위치에 보를 우선 제거
                if (!canDeleteBo(y, x))
                    PLATE[y][x] = 1;
            }
        }
    }

    for (int y = 0; y <= L; y++) {                  // O(N^2)
        for (int x = 0; x <= L; x++) {
            if (BAR[y][x] == 1)
                answer.push_back({ x, y, 0 });
        }
    }

    for (int y = 0; y <= L; y++) {                  // O(N^2)
        for (int x = 0; x <= L; x++) {
            if (PLATE[y][x] == 1)
                answer.push_back({ x, y, 1 });
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {

    int n = 5;
    //vector<vector<int>> build_frame = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    //vector<vector<int>> build_frame = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    vector<vector<int>> build_frame = { 
        {0,0,0,1},
        {0,1,0,1},
        {0,2,0,1},
        
        {3,0,0,1},
        {3,1,0,1},
        {3,2,0,1},

        {0,3,1,1},
        {2,3,1,1},
        {1,3,1,1},
        
        

        {2,3,1,0},
    };

    vector<vector<int>> answer = solution(n, build_frame);

    cout << "hello";

    return 0;
}
