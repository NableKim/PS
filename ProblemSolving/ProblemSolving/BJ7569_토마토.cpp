// 시간복잡도 : O(N*M*H)

#include <iostream>
#include <queue>
using namespace std;

int X, Y, H;

struct P {
	int h, y, x;
};

int map[100][100][100];
int visited[100][100][100];

int dh[] = {-1, 1, 0, 0, 0, 0};
int dy[] = { 0, 0, -1, 0, 1, 0 };
int dx[] = { 0, 0, 0, -1, 0, 1 };

void bfs(int h, int y, int x) {
	
	queue<P> q;
	q.push({ h, y, x });
	visited[h][y][x] = 1;

	while (!q.empty()) {
		P f = q.front(); q.pop();

		for (int k = 0; k < 6; k++) {
			int nh = f.h + dh[k];
			int ny = f.y + dy[k];
			int nx = f.x + dx[k];

			if (nh < 0 || nh >= H || ny < 0 || ny >= Y || nx < 0 || nx >= X)
				continue;

			if (map[nh][ny][nx] == 1 || map[nh][ny][nx] == -1)
				continue;
			
			if (visited[nh][ny][nx] == 0 || visited[nh][ny][nx] > visited[f.h][f.y][f.x] + 1) {
				visited[nh][ny][nx] = visited[f.h][f.y][f.x] + 1;
				q.push({ nh, ny, nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//	freopen("Text.txt", "r", stdin);

	cin >> X >> Y >> H;

	int raw = 0;
	for (int h = 0; h < H; h++) {
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				cin >> map[h][y][x];
				if (map[h][y][x] == 0)
					raw++;
			}
		}
	}

	if (raw == 0) {
		cout << 0;
		return 0;
	}

	for (int h = 0; h < H; h++) {
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				if (map[h][y][x] == 1 && visited[h][y][x]==0)
					bfs(h, y, x);
			}
		}
	}
	
	int maxVal = -1;
	for (int h = 0; h < H; h++) {
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				if (visited[h][y][x] > maxVal)
					maxVal = visited[h][y][x];
				
				if (visited[h][y][x]==0 && map[h][y][x] == 0) {
					cout << -1;
					return 0;
				}

			}
		}
	}

	cout << maxVal - 1;

	return 0;
}