#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct POINT {
	int x, y;	// 시작점 x, 끝점 y
};

bool cmp(POINT& a, POINT& b) {
	return a.x < b.x;
}

int main() {
	int N;
	vector<POINT> v;
	
	scanf(" %d", &N);

	for (int i = 0, x, y; i < N; i++)
	{
		scanf(" %d %d", &x, &y);
		v.push_back({ x,y });
	}

	// x좌표를 기준으로 오름차순 정렬
	sort(v.begin(), v.end(), cmp);

	// 첫번째 선분의 시작점을 시작으로 탐색 시작
	int cy = v[0].y, cx = v[0].x;
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		// 겹치는 선분이라면
		if (cx <= v[i].x && v[i].x <= cy) {
			// 선을 잇는 경우
			if (cy < v[i].y)
				cy = v[i].y;
		}
		else {
			ans += (cy - cx);
			cy = v[i].y;
			cx = v[i].x;
		}
	}

	ans += (cy - cx);
	printf("%d", ans);
	return 0;
}