#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct SCHEDULE {
	int s, e;
};

bool cmp(SCHEDULE& a, SCHEDULE& b) {
	if (a.e == b.e)
		return a.s < b.s;
	return a.e < b.e;
}

int main() {
	int N;
	vector<SCHEDULE> v;

	scanf(" %d", &N);

	for (int i = 0, s, e; i < N; i++)
	{
		scanf(" %d %d", &s, &e);
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(), cmp);

	int ans = 0;
	int ee=0;	// 마지막 회의가 끝난 시간
	for (int i = 0, s, e; i < N; i++)
	{
		if (ee <= v[i].s) {
			ans++;
			ee = v[i].e;
		}
	}

	printf("%d", ans);

	return 0;
}