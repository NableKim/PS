#include <cstdio>
#include <vector>
using namespace std;

int main() {

	int T;
	scanf(" %d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf(" %d", &N);

		vector<int> v;
		for (int i = 0; i < N; i++) {
			int input;
			scanf("%d", &input);
			v.push_back(input);
		}

		int maxVal = v[N - 1];
		long long profit = 0;
		for (int i = N - 2; i >= 0; i--) {
			if (maxVal > v[i]) {
				profit += (long long)(maxVal - v[i]);
			}
			else {
				maxVal = v[i];
			}
		}

		printf("%lld\n", profit);
	}

	return 0;
}