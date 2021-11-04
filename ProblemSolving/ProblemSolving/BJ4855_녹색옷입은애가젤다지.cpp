/*
bfs를 이용한 최단 거리(최소 비용) 찾기
*/

#include <iostream>
#include <queue>
using namespace std;

#define N_MAX 125
#define INF 987654321

struct P {
	int y, x, c;
};

int map[N_MAX][N_MAX];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int N;

int bfs() {

	int check[N_MAX][N_MAX];;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++)
			check[y][x] = INF;
	}

	queue<P> q;
	q.push({ 0, 0, map[0][0] });
	check[0][0] = map[0][0];

	while (!q.empty()) {

		P front = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = front.y + dy[k];
			int nx = front.x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			int nc = front.c + map[ny][nx];
			if (nc < check[ny][nx]) {
				q.push({ ny, nx, nc });
				check[ny][nx] = nc;
			}
		}

	}
	
	return check[N-1][N-1];
}

int main() {
	
	//freopen("Text.txt", "r", stdin);

	int tc = 1;
	while (1) {
		cin >> N;

		if (N == 0) break;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}

		cout << "Problem " << tc++ << ": " << bfs() << "\n";
	}

	return 0;
}