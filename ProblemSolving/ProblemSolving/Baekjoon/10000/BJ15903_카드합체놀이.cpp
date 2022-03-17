#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<long long, vector<long long>, greater<>> pq;

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, M;
	scanf(" %d %d", &N, &M);

	long long input;
	for (int i = 0; i < N; i++) {
		scanf(" %lld", &input);
		pq.push(input);
	}

	for (int i = 0; i < M; i++) {
		long long val1 = pq.top(); pq.pop();
		long long val2 = pq.top(); pq.pop();
		long long tmp = val1 + val2;
		pq.push(tmp);
		pq.push(tmp);
	}

	long long answer = 0;
	while (!pq.empty()) {
		answer += pq.top(); pq.pop();
	}
	printf("%lld", answer);

	return 0;
}