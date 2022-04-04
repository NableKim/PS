#include <string>
using namespace std;

bool visited[11][11][4];

int solution(string dirs) {
    int answer = 0;
    int cy, cx;

    cy = cx = 5;
    for (int i = 0; i < dirs.length(); i++) {
        int ny, nx, nd;
        if (dirs[i] == 'U') {
            ny = cy + 1;
            nx = cx;
            nd = 0;
        }
        else if (dirs[i] == 'D') {
            ny = cy - 1;
            nx = cx;
            nd = 2;
        }
        else if (dirs[i] == 'L') {
            ny = cy;
            nx = cx - 1;
            nd = 1;
        }
        else {
            ny = cy;
            nx = cx + 1;
            nd = 3;
        }

        if (ny < 0 || ny > 10 || nx < 0 || nx > 10) continue;
        if (!visited[ny][nx][nd]) answer++;

        visited[cy][cx][(nd + 2) % 4] = true;
        visited[ny][nx][nd] = true;
        cy = ny;
        cx = nx;
    }

    return answer;
}