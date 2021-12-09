#include <cstdio>
using namespace std;

int map[128][128];

int blue, white;

void recursive_quarter_divide(int sy, int sx, int len) {

	bool flag = true;
	int base = map[sy][sx];
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			if (base != map[sy + y][sx + x]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag) {
		if (map[sy][sx])
			blue++;
		else
			white++;
		return;
	}

	int nextLen = len / 2;
	recursive_quarter_divide(sy, sx, nextLen);
	recursive_quarter_divide(sy, sx+ nextLen, nextLen);
	recursive_quarter_divide(sy+ nextLen, sx, nextLen);
	recursive_quarter_divide(sy+ nextLen, sx+ nextLen, nextLen);
}

int main() {

	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %d", &map[i][j]);
		}
	}

	recursive_quarter_divide(0, 0, N);

	printf("%d\n", white);
	printf("%d", blue);

	return 0;
}