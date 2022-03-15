#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define edge_SIZE 100

bool edge[edge_SIZE][edge_SIZE][4];
bool visited[edge_SIZE][edge_SIZE];
bool map[edge_SIZE][edge_SIZE];
int dy[] = { -1, 0, 1, 0 };	// 상좌하우
int dx[] = { 0, -1, 0, 1 };

struct POINT {
	int y, x;
};

int bfs(int n, int sy, int sx) {

	queue<POINT> q;
	visited[sy][sx] = true;
	q.push({ sy, sx });
	
	int cnt = 0;
	while (!q.empty()) {

		POINT front = q.front(); q.pop();
		if(map[front.y][front.x])
			cnt++;

		for (int i = 0; i < 4; i++) {
			if (edge[front.y][front.x][i]) continue;

			int ny = front.y + dy[i];
			int nx = front.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return cnt;
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, K, R;
	scanf(" %d %d %d", &N, &K, &R);

	// 길 정보
	POINT p1, p2;
	for (int i = 0; i < R; i++)
	{
		scanf(" %d %d", &p1.y, &p1.x);
		scanf(" %d %d", &p2.y, &p2.x);

		p1.y--; p1.x--;
		p2.y--; p2.x--;

		for (int k = 0; k < 4; k++) {
			int ty = p1.y + dy[k];
			int tx = p1.x + dx[k];

			if (p2.y == ty && p2.x == tx) {
				edge[p1.y][p1.x][k] = true;
				edge[p2.y][p2.x][(k+2)%4] = true;
				break;
			}
		}
	}

	for (int i = 0, y, x; i < K; i++) {
		scanf(" %d %d", &y, &x);
		map[y - 1][x - 1] = true;
	}

	vector<int> cowCntList;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (!visited[y][x]) {
				int cnt = bfs(N, y, x);
				if (cnt)
					cowCntList.push_back(cnt);
			}
		}
	}

	int answer = 0;
	int subSum = 0;
	for (int i = 0; i < cowCntList.size(); i++)
	{
		answer += cowCntList[i] * (K - cowCntList[i] - subSum);
		subSum += cowCntList[i];
	}

	printf("%d", answer);

	return 0;
}