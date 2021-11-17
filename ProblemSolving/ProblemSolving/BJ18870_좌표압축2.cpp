#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct P {
	int val, idx;
};

vector<P> v;

int result[1000000];

bool cmp(P& a, P& b) {
	return a.val < b.val;
}

int main() {

	int N;
	scanf(" %d", &N);

	for (int i = 0, input; i < N; i++) {
		scanf(" %d", &input);

		v.push_back({ input, i });
	}

	sort(v.begin(), v.end(), cmp);

	int pre = v[0].val;
	int cnt = 0;
	result[v[0].idx] = 0;

	for (int i = 1; i < N; i++) {

		if (pre != v[i].val) {
			cnt++;
			pre = v[i].val;
		}

		result[v[i].idx] = cnt;
	}

	for (int i = 0; i < N; i++)
		printf("%d ", result[i]);

	return 0;
}