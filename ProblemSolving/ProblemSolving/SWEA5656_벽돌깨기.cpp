#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct P {
	int y, x, d;
};

vector<int> pick;
int T, N, X, Y;
int map[15][12];
int map_bk[15][12];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int answer;
int total_brick;

void init() {
	total_brick = 0;
	answer = 987654321;
	pick.clear();
}

// 구슬이 부딪히는 최초의 행을 찾기
int getCollisionY(int x) {
	int y = 0;
	while (y<Y && map[y][x] == 0)
		y++;
	return y;
}

void drop_brick(int x) {

	// 실제 벽돌들의 번호를 아래에서부터 저장
	queue<int> q;

	int y;
	for (y = Y - 1; y >= 0; y--) {
		if (map[y][x] != 0) {
			q.push(map[y][x]);
			map[y][x] = 0;
		}
	}
	
	// 벽돌 아래서부터 숫자 채워주기
	y = Y - 1;
	while (!q.empty()) {
		map[y--][x] = q.front();
		q.pop();
	}
}

int game_start() {

	int bomb = 0;
	// N번 떨구기
	for (int i = 0; i < pick.size(); i++) {

		// 최초 충돌지점 확인
		int col = pick[i];
		int row = getCollisionY(col);

		if (row == Y)
			continue;

		// 최초 충돌지점을 기준으로 연쇄적으로 터지는 지점 확인
		
		bool check[15][12] = { false, };
		queue<P> q;

		q.push({ row, col, map[row][col]-1 });
		//v.push_back({ row, col });
		check[row][col] = true;
		map[row][col] = 0;

		// 연쇄적으로 터지는 모든 좌표들을 v에 저장
		while (!q.empty()) {
			P front = q.front();
			q.pop();
			bomb++;
		
			// 터지는 지점의 사정거리
			int r = front.d;

			int ny, nx;
			for (int k = 0; k < 4; k++) {
				for(int range = 1; range <= r; range++) {
					ny = front.y + (dy[k]*range);
					nx = front.x + (dx[k]*range);

					if (ny < 0 || ny >= Y || nx < 0 || nx >= X)
						break;

					if (check[ny][nx] || map[ny][nx] == 0)
						continue;

					check[ny][nx] = true;
					q.push({ ny, nx, map[ny][nx]-1 });
					//v.push_back({ ny, nx });
					map[ny][nx] = 0;
				}
			}
		}

		// 빈곳이 생겼을테니 아래로 내려주기
		for (int x = 0; x < X; x++)
			drop_brick(x);
	}
	return bomb;
}


void dfs(int depth) {

	if (answer == 0)
		return;

	if (depth == N) {

		// 게임판 백업
		memcpy(map_bk, map, sizeof(map));
	
		// 게임 시작
		int score = total_brick - game_start();
		answer = answer > score ? score : answer;
		
		// 게임판 복구
		memcpy(map, map_bk, sizeof(map));
		
		return;
	}
	
	for (int i = 0; i < X; i++) {
		pick.push_back(i);
		dfs(depth + 1);
		pick.pop_back();
	}
}

int main() {

	// 0~(W-1) 중에 N개 고르기 >> 중복 순열 구하기
	// 구슬을 떨궜을때 최초 터지는 지점 찾기
	// 최초 터지는 지점을 기준으로 반경 k 길이에서 또 터지는 얘들 구하기
	// 또 터지는 얘들에 의해서 연쇄적으로 터지는 좌표들 구하기
	// 모두 0 넣어주기
	// 모든 열에 대해서 밑으로 내려주기

	//freopen("Text.txt", "r", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 1; t <= T; t++) {

		init();

		cin >> N >> X >> Y;

		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				cin >> map[y][x];
				if (map[y][x] != 0)
					total_brick++;
			}
		}

		// 몇번열에 N 번 떨굴 것인가
		dfs(0);

		cout << "#" << t << " " << answer << "\n";
	}

	return 0;
}