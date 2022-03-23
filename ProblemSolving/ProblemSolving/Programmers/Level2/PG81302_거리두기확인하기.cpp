#include <string>
#include <vector>
#include <queue>
using namespace std;

struct P {
    int y, x;
};

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool bfs(int sy, int sx, vector<string>& place) {
    int visited[5][5] = { 0, };
    visited[sy][sx] = 1;
    queue<P> q;
    q.push({ sy, sx });

    while (!q.empty()) {
        P front = q.front();
        q.pop();

        // 맨허튼 거리 2이상은 스킵
        if (visited[front.y][front.x] == 3)
            break;

        for (int k = 0; k < 4; k++) {
            int ny = front.y + dy[k];
            int nx = front.x + dx[k];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if (place[ny][nx] == 'X') continue;
            if (visited[ny][nx] > 0) continue;

            if (place[ny][nx] == 'P' && visited[front.y][front.x] + 1 <= 3)
                return false;

            visited[ny][nx] = visited[front.y][front.x] + 1;
            q.push({ ny, nx });
        }
    }
    return true;
}

bool checkSafe(vector<string>& place) {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (place[y][x] == 'P') {
                if (!bfs(y, x, place))
                    return false;제
            }
        }
    }
    return true;

}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;


    for (int p = 0; p < 5; p++) {

        if (checkSafe(places[p]))
            answer.push_back(1);
        else
            answer.push_back(0);

    }



    return answer;
}