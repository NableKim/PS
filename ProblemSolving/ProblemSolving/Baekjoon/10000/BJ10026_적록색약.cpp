#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int map[100][100];

int cnt[2];
int N;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

struct P {
	int y, x;
};

void bfs(int sy, int sx, int visit[][100], bool flag) {
	
	queue<P> q;
	q.push({ sy, sx });
	visit[sy][sx] = 1;

	while (!q.empty()) {
		P p = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = p.y + dy[k];
			int nx = p.x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (visit[ny][nx])
				continue;

			if (flag == false){
				if (map[ny][nx] == map[sy][sx]) {
					q.push({ ny, nx });
					visit[ny][nx] = true;
				}
			}
			else {
				if (map[ny][nx] % 2 == map[sy][sx] % 2) {
					q.push({ ny, nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
}

int main() {

	scanf("%d", &N);
	
	char input;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf(" %c", &input);
			if (input == 'R')
				map[y][x] = 1;
			else if (input == 'G')
				map[y][x] = 3;
			else
				map[y][x] = 2;
		}
	}

	int visit[100][100] = { 0, };
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!visit[y][x]) {
				bfs(y, x, visit, false);
				cnt[0]++;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!visit[y][x]) {
				bfs(y, x, visit, true);
				cnt[1]++;
			}
		}
	}

	printf("%d %d", cnt[0], cnt[1]);

	return 0;
}