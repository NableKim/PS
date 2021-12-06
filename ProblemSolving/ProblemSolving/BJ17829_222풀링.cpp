#include <cstdio>
using namespace std;

int map[1024][1024];

int second_max(int sy, int sx) {

	int first = -20000;
	int second = -30000;

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			if (first <= map[sy + y][sx + x]) {
				second = first;
				first = map[sy + y][sx + x];
			} 
			else if(map[sy + y][sx + x] > second)
				second = map[sy + y][sx + x];
		}
	}
	return second;
}

//int polling(int N) {
//
//	if (N == 1) {
//		return map[0][0];
//	}
//
//	int nextN = N / 2;
//	for (int y = 0; y < nextN; y++) {
//		for (int x = 0; x < nextN; x++) {
//			map[y][x] = second_max(y * 2, x * 2);
//		}
//	}
//
//	polling(nextN);
//}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf(" %d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf(" %d", &map[y][x]);
		}
	}

	while (N != 1) {

		int nextN = N / 2;
		for (int y = 0; y < nextN; y++) {
			for (int x = 0; x < nextN; x++) {
				map[y][x] = second_max(y * 2, x * 2);
			}
		}

		N /= 2;
	}

	printf("%d", map[0][0]);

	return 0;
}