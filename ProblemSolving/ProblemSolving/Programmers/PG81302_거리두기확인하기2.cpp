/*
* BFS를 활용하여 맨해튼 거리 2이하에 사람이 있는지 확인하는 방식으로 접근
* 시간복잡도 : O(N^2), N은 대기실의 면접 대기실 한변의 길이
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct P {
    int y, x;
};

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// 주어진 대기실 map에 대해서 맨해튼 거리 2이하만큼 bfs 탐색
bool bfs(int idx, int sy, int sx, vector<string> map) {
    
    queue<P> q;
    int check[5][5] = { 0, };
    check[sy][sx] = 1;
    q.push({ sy, sx });

    while (!q.empty()) {

        P front = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = front.y + dy[k];
            int nx = front.x + dx[k];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
                continue;

            if(check[ny][nx])
                continue;

            if (map[ny][nx] == 'X')
                continue;

            // 맨해튼 거리 2까지만 확인하기
            int nextDis = check[front.y][front.x] + 1;
            if (nextDis <= 3) {
                if (map[ny][nx] == 'P')
                    return false;

                check[ny][nx] = nextDis;
                q.push({ ny, nx });
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // 각 대기실에 대하여 거리두기 판별
    for (int i = 0; i < places.size(); i++) {
        
        int flag = 1;   // 정답 산출을 위한 flag

        // 한 대기실의 Map을 가지고 bfs 수행
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                // 사람이 위치한 곳을 싲가점으로 맨해튼 거리 2 반경만큼 bfs 탐색
                if (places[i][y][x] == 'P' 
                    && !bfs(i, y, x, places[i])) {
                    flag = 0;
                    break;
                }
            }

            if (flag == 0)
                break;
        }

        if (flag) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}

int main() {

    //vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    vector<vector<string>> places = { 
        {
            "PXPOO", 
            "XPXOO", 
            "OPOOO", 
            "OOOOO", 
            "OOOOO", 
        }, 
    };

    vector<int> answer = solution(places);

    for (int& a : answer)
        cout << a << " ";

    return 0;
}