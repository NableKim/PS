#include <cstdio>
using namespace std;

int map[26][26];
int answer = 0;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int Y, X;

void dfs(int sy, int sx, int cnt, bool check[]) {

	if (cnt > answer)
		answer = cnt;

	for (int k = 0; k < 4; k++) {
		int ny = sy + dy[k];
		int nx = sx + dx[k];

		if (ny < 0 || ny >= Y || nx < 0 || nx >= X)
			continue;

		if (check[map[ny][nx]])
			continue;

		check[map[ny][nx]] = true;
		dfs(ny, nx, cnt + 1, check);
		check[map[ny][nx]] = false;
	}
}

int main() {
	
	scanf(" %d %d", &Y, &X);

	char ch;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			scanf(" %c", &ch);
			map[y][x] = ch - 'A';
		}
	}
	
	bool check[26] = { false, };
	check[map[0][0]] = true;
	dfs(0, 0, 1, check);

	printf("%d", answer);

	return 0;
}