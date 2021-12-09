#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct P {
	int idx, val;
};



int lower_bound(int l, int r, vector<int>& v2, int target) {

	if (v2.empty() || v2[r] < target)
		return -1;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (v2[mid] >= target)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return r + 1;
}

int main() {

	int N;
	scanf(" %d", &N);

	vector<int> v;
	for (int i = 0, input; i < N; i++) {
		scanf(" %d", &input);
		v.push_back(input);
	}

	vector<int> v2;
	vector<P> note;
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(0, v2.size()-1, v2, v[i]);
		if (idx == -1) {
			v2.push_back(v[i]);
			note.push_back({ (int)v2.size()-1, v[i] });
		}
		else {
			v2[idx] = v[i];
			note.push_back({ idx, v[i] });
		}
	}

	stack<int> s;
	int t = v2.size()-1;
	for (int i = N - 1; i >= 0; i--) {
		if (t == note[i].idx) {
			s.push(note[i].val);
			t--;
		}
	}

	printf("%d\n", v2.size());
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}


	return 0;
}