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

// ������ �ε����� ������ ���� ã��
int getCollisionY(int x) {
	int y = 0;
	while (y<Y && map[y][x] == 0)
		y++;
	return y;
}

void drop_brick(int x) {

	// ���� �������� ��ȣ�� �Ʒ��������� ����
	queue<int> q;

	int y;
	for (y = Y - 1; y >= 0; y--) {
		if (map[y][x] != 0) {
			q.push(map[y][x]);
			map[y][x] = 0;
		}
	}
	
	// ���� �Ʒ������� ���� ä���ֱ�
	y = Y - 1;
	while (!q.empty()) {
		map[y--][x] = q.front();
		q.pop();
	}
}

int game_start() {

	int bomb = 0;
	// N�� ������
	for (int i = 0; i < pick.size(); i++) {

		// ���� �浹���� Ȯ��
		int col = pick[i];
		int row = getCollisionY(col);

		if (row == Y)
			continue;

		// ���� �浹������ �������� ���������� ������ ���� Ȯ��
		
		bool check[15][12] = { false, };
		queue<P> q;

		q.push({ row, col, map[row][col]-1 });
		//v.push_back({ row, col });
		check[row][col] = true;
		map[row][col] = 0;

		// ���������� ������ ��� ��ǥ���� v�� ����
		while (!q.empty()) {
			P front = q.front();
			q.pop();
			bomb++;
		
			// ������ ������ �����Ÿ�
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

		// ����� �������״� �Ʒ��� �����ֱ�
		for (int x = 0; x < X; x++)
			drop_brick(x);
	}
	return bomb;
}


void dfs(int depth) {

	if (answer == 0)
		return;

	if (depth == N) {

		// ������ ���
		memcpy(map_bk, map, sizeof(map));
	
		// ���� ����
		int score = total_brick - game_start();
		answer = answer > score ? score : answer;
		
		// ������ ����
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

	// 0~(W-1) �߿� N�� ���� >> �ߺ� ���� ���ϱ�
	// ������ �������� ���� ������ ���� ã��
	// ���� ������ ������ �������� �ݰ� k ���̿��� �� ������ ��� ���ϱ�
	// �� ������ ��鿡 ���ؼ� ���������� ������ ��ǥ�� ���ϱ�
	// ��� 0 �־��ֱ�
	// ��� ���� ���ؼ� ������ �����ֱ�

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

		// ������� N �� ���� ���ΰ�
		dfs(0);

		cout << "#" << t << " " << answer << "\n";
	}

	return 0;
}