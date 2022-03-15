#include <cstdio>
using namespace std;

int map[100][100];
int map2[100][100];
int N, M, R;

void map2_to_map_cpy() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			map[y][x] = map2[y][x];
		}
	}
}

void func1() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			map2[N - 1 - y][x] = map[y][x];
		}
	}

	map2_to_map_cpy();
}

void func2() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			map2[y][M-1-x] = map[y][x];
		}
	}

	map2_to_map_cpy();
}

void func3() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			map2[x][N - 1 - y] = map[y][x];
		}
	}

	int tmp = N;
	N = M;
	M = tmp;

	map2_to_map_cpy();
}

void func4() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			map2[M-1-x][y] = map[y][x];
		}
	}

	int tmp = N;
	N = M;
	M = tmp;

	map2_to_map_cpy();
}

void quarter_change(int y1, int x1, int y2, int x2) {

	int n = N / 2;
	int m = M / 2;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			map2[y2+y][x2+x] = map[y1 + y][x1 + x];
		}
	}
}

void func5() {
	quarter_change(0, 0, 0, M / 2);
	quarter_change(0, M / 2, N / 2, M / 2);
	quarter_change(N / 2, M / 2, N / 2, 0);
	quarter_change(N / 2, 0, 0, 0);

	map2_to_map_cpy();
}

void func6() {
	quarter_change(0, M / 2, 0, 0);
	quarter_change(0, 0, N / 2, 0);
	quarter_change(N / 2, 0, N / 2, M / 2);
	quarter_change(N / 2, M / 2, 0, M / 2);

	map2_to_map_cpy();
}

int main() {

	//freopen("Text.txt", "r", stdin);

	scanf(" %d %d %d", &N, &M, &R);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf(" %d", &map[y][x]);
		}
	}

	for (int r = 0, op; r < R; r++) {
		scanf(" %d", &op);
		switch (op) {
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
		case 3:
			func3();
			break;
		case 4:
			func4();
			break;
		case 5:
			func5();
			break;
		case 6:
			func6();
			break;
		default:
			break;
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}

	return 0;
}
