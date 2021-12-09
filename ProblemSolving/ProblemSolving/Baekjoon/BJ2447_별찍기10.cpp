#include <cstdio>
#include <cstring>
using namespace std;

void func(int sy, int sx, int l, bool **map) {

	if (l == 3) {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				map[sy + y][sx + x] = true;
			}
		}
		map[sy + 1][sx + 1] = false;
		return;
	}

	int nl = l / 3;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (y == 1 && x == 1) continue;
			func(sy + (nl * y), sx + (nl * x), nl, map);
		}
	}

}

int main() {

	int N;
	scanf(" %d", &N);

	bool** map = new bool*[N];
	for (int i = 0; i < N; i++)
		map[i] = new bool[N];

	for (int i = 0; i < N; i++)
		memset(map[i], false, N * sizeof(bool));
	
	func(0, 0, N, map);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++)
		delete[] map[i];
	delete[] map;

	return 0;
}