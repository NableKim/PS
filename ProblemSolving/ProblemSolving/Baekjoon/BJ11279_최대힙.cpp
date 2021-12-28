#include <cstdio>
#include <queue>
using namespace std;

int main() {

	//freopen("Text.txt", "r", stdin);

	priority_queue<int> pq;

	int N;
	scanf("%d", &N);

	int input;
	for (int i = 0; i < N; i++) {
		scanf(" %d", &input);
		if (input == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}

	return 0;
}