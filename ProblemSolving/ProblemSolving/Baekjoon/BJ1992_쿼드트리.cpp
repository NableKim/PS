#include <cstdio>
#include <string>
using namespace std;

int map[64][64];

string divide_quarter(int sy, int sx, int len) {

	if (len == 1)
		return to_string(map[sy][sx]);

	bool diffFlag = false;
	int pre = map[sy][sx];
	for (int y = sy; y < sy + len; y++) {
		for (int x = sx; x < sx + len; x++) {
			if (pre != map[y][x]) {
				diffFlag = true;
				break;
			}
		}
		if (diffFlag)
			break;
	}

	if (!diffFlag)
		return to_string(map[sy][sx]);

	int nextLen = len / 2;
	return "("
		+ divide_quarter(sy, sx, nextLen)
		+ divide_quarter(sy, sx + nextLen, nextLen)
		+ divide_quarter(sy + nextLen, sx, nextLen)
		+ divide_quarter(sy + nextLen, sx + nextLen, nextLen)
		+ ")";
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf(" %d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf(" %1d", &map[y][x]);
		}
	}

	string answer = divide_quarter(0, 0, N);
	printf("%s", answer.c_str());
	

	return 0;
}