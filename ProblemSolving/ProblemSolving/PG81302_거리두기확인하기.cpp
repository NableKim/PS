#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct _P {
    int y, x;
} P;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool bfs(int y, int x, vector<string> room) {
    queue<P> q;
    int visited[5][5] = { 0, };
    visited[y][x] = 1;
    q.push({ y, x });

    while (!q.empty()) {
        P p = q.front(); q.pop();
        
        for (int k = 0; k < 4; k++) {
            int ny, nx;
            ny = p.y + dy[k];
            nx = p.x + dx[k];
        
            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if (visited[ny][nx] || room[ny][nx] == 'X') continue;
            
            if (room[ny][nx] == 'O') {
                visited[ny][nx] = visited[p.y][p.x] + 1;
                q.push({ ny, nx });
            }
            else if(room[ny][nx] == 'P') {
                if (visited[p.y][p.x] + 1 <= 3)
                    return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (vector<string>& room : places) {
        
        bool flag = true;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (room[y][x] == 'P') {
                    if (!bfs(y, x, room)) {
                        flag = false;
                        break;
                    }
                }
            }
            
            if (!flag)
                break;
        }

        if (flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}

int main() {

    vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    
    vector<int> answer= solution(places);
    for (int& a : answer)
        printf(" %d", a);

    return 0;
}