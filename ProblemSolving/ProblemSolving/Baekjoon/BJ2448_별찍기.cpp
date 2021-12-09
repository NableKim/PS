#include <cstdio>
using namespace std;

bool map[3072][6144];

void dfs(int y, int x, int len) {

	if (len == 3) {
		map[y][x] = true;
		map[y + 1][x - 1] = map[y + 1][x + 1] = true;
		map[y + 2][x - 2] = map[y + 2][x - 1] = true;
		map[y + 2][x + 2] = map[y + 2][x + 1] = true;
		map[y + 2][x] = true;
		return;
	}

	dfs(y, x, len / 2);
	dfs(y + len/2, x - len/2, len / 2);
	dfs(y + len/2, x + len/2, len / 2);
}

int main() {
	int N;
	scanf("%d", &N);

	dfs(0, N-1, N);
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 2 * N; x++) {
			if (map[y][x])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}