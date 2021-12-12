#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int lower_bound(int left, int right, int target) {
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (v[mid] >= target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right - 1;
}
int upper_bound(int left, int right, int target) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (v[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right - 1;
}

int main() {
	int N, M;
	scanf(" %d", &N);

	for (int i = 0, input; i < N; i++) {
		scanf(" %d", &input);
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	scanf(" %d", &M);

	for (int i = 0, input; i < M; i++) {
		scanf(" %d", &input);
		int lower_idx = lower_bound(0, v.size() - 1, input);
		int upper_idx = upper_bound(0, v.size() - 1, input);
		printf("%d ", upper_idx - lower_idx);
	}

	return 0;
}