#include <cstdio>
using namespace std;

int cnt, answer;
int N, R, C;

int getSectionNumber(int sy, int sx, int len) {

	// 0, 1
	if (sy <= R && R < sy + len) {
		if (sx <= C && C < sx + len)
			return 0;
		else
			return 1;
	}
	else {	// 2, 3
		if (sx <= C && C < sx + len)
			return 2;
		else
			return 3;
	}
}

void func(int sy, int sx, int len) {

	if (len == 1) {
		if (sy == R && sx == C)
			answer = cnt;
		cnt++;
		return;
	}

	int nextLen = len / 2;
	int section = getSectionNumber(sy, sx, nextLen);
	
	cnt += (nextLen * nextLen) * section;
	if (section == 0)
		func(sy, sx, nextLen);
	else if (section == 1)
		func(sy, sx + nextLen, nextLen);
	else if (section == 2)
		func(sy + nextLen, sx, nextLen);
	else
		func(sy + nextLen, sx + nextLen, nextLen);
}

int pow(int n) {
	int val = 1;
	while (n--) {
		val *= 2;
	}
	return val;
}

int main() {
	
	scanf(" %d %d %d", &N, &R, &C);

	func(0, 0, pow(N));
	
	printf("%d", answer);

	return 0;
}