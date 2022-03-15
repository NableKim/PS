#include <cstdio>
using namespace std;

#define MAX_LEN 2187

int map[MAX_LEN][MAX_LEN];
int cnt[3];

void func(int sy, int sx, int len) {
	
	if (len == 1) {
		cnt[map[sy][sx] + 1]++;
		return;
	}

	bool diff = true;
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			if (map[sy][sx] != map[sy + y][sx + x]) {
				diff = false;
				break;
			}
		}
		if (!diff) break;
	}

	if(diff) {
		cnt[map[sy][sx] + 1]++;
		return;
	}

	int nextLen = len / 3;
	func(sy, sx, nextLen);
	func(sy, sx+ nextLen, nextLen);
	func(sy, sx+ nextLen+ nextLen, nextLen);
	func(sy + nextLen, sx, nextLen);
	func(sy + nextLen, sx + nextLen, nextLen);
	func(sy + nextLen, sx + nextLen + nextLen, nextLen);
	func(sy + nextLen + nextLen, sx, nextLen);
	func(sy + nextLen + nextLen, sx + nextLen, nextLen);
	func(sy + nextLen + nextLen, sx + nextLen + nextLen, nextLen);
}

int main() {

	int N;
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf(" %d", &map[y][x]);
		}
	}

	func(0, 0, N);

	for (int i = 0; i < 3; i++)
		printf("%d\n", cnt[i]);

	return 0;
}