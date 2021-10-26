/*
���� h ���ϱ� >> ��� ħ���ǰų� ħ�� �ȵǴ� �� �ǹ� ������ ���� �ּҰ�+1 ~ �ִ밪-1 ���� ���� ����
h ������ ���� ��� ħ�� ��Ű��
ħ�� �ȵ� ������ �߽����� bfs Ž�� �� ���� ī��Ʈ
���� �ִ밪 ����
*/

#include <iostream>
#include <queue>
using namespace std;

struct P {
	int y, x;
};

int N;
int map[100][100];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void bfs(int y, int x, int h, bool check[100][100]) {

	queue<P> q;
	check[y][x] = true;
	q.push({ y, x });

	while (!q.empty()) {
		P front = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = front.y + dy[k];
			int nx = front.x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (map[ny][nx] <= h || check[ny][nx])
				continue;

			q.push({ ny, nx });
			check[ny][nx] = true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	cin >> N;

	int	minVal = 9999;
	int maxVal = -1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (minVal > map[y][x])
				minVal = map[y][x];
			if (maxVal < map[y][x])
				maxVal = map[y][x];
		}
	}

	int answer = 1;
	for (int h = minVal; h < maxVal; h++) {
		
		bool check[100][100] = { false, };

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] <= h )
					check[y][x] = true;
			}
		}

		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] > h && !check[y][x]) {
					bfs(y, x, h, check);
					cnt++;
				}
			}
		}

		if (answer < cnt)
			answer = cnt;
	}
	
	cout << answer;

	return 0;
}