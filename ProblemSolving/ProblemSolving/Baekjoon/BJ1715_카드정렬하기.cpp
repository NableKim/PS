#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {

	int N;
	scanf(" %d", &N);

	for (int i = 0, input; i < N; i++) {
		scanf(" %d", &input);
		pq.push(input);
	}

	int answer = 0;
	while (pq.size() > 1) {
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();

		int sum = first + second;
		answer += sum;
		pq.push(sum);
	}

	printf("%d", answer);

	return 0;
}