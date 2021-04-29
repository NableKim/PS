#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[20][20];
int sy, sx;	// 상어 위치

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int ss = 2;	// 상어 size
int eaten = 0;	// 지금까지 먹은 먹이수
int t;

struct POINT {
	int y, x;
};

bool cmp(POINT a, POINT b) {
	if (a.y == b.y) 
		return a.x < b.x;
	return a.y < b.y;
}

bool bfs() {

	queue<POINT> q;
	int visited[20][20] = { 0, };
	vector<POINT> candi;

	q.push({ sy, sx });
	visited[sy][sx] = 1;

	int dis = 0;	// 최초 발견한 먹이까지의 거리
	while (!q.empty()) {
		POINT front = q.front();
		q.pop();

		// 최초로 찾은 먹이까지의 거리보다 더 멀리갈 필요 없음
		if (dis !=0 && dis <= visited[front.y][front.x])
			break;

		for (int k = 0; k < 4; k++) {
			int ny = front.y + dy[k];
			int nx = front.x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (visited[ny][nx] > 0)
				continue;

			// 빈칸이거나 상어랑 동일한 크기라면
			if (map[ny][nx] == 0 || map[ny][nx] == ss) {
				q.push({ ny, nx });
				visited[ny][nx] = visited[front.y][front.x] + 1;
			}
			else if (map[ny][nx] < ss) {
				// 먹이 발견
				if (dis == 0) {
					visited[ny][nx] = visited[front.y][front.x] + 1;
					dis = visited[ny][nx];
					candi.push_back({ ny, nx });	// 먹이 후보
				}
				else {
					visited[ny][nx] = visited[front.y][front.x] + 1;
					candi.push_back({ ny, nx });	// 먹이 후보
				}
			}
		}
	}

	// 먹이를 못찾았다면
	if (dis == 0)
		return false;

	sort(candi.begin(), candi.end(), cmp);

	POINT p = candi[0];
	
	map[sy][sx] = 0;	// 상어 위치 비우고
	sy = candi[0].y;	
	sx = candi[0].x;
	map[sy][sx] = 9;	// 상어 다음 위치로
	eaten++;

	if (eaten == ss) {
		ss++;
		eaten = 0;
	}

	t += (visited[sy][sx] - 1);

	return true;
}

int main() {

	freopen("Text.txt", "r", stdin);

	scanf(" %d", &N);
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf(" %d", &map[y][x]);
			if (map[y][x]==9) {
				sy = y;
				sx = x;
			}
		}
	}

	while (1) {
		// 먹이 탐색 시작
		if (!bfs())
			break;
	}

	printf("%d", t);

	return 0;
}