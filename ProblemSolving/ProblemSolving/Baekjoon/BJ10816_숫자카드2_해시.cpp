#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;

int main() {
	int N, M;

	scanf(" %d", &N);
	for (int i = 0, input; i < N; i++) {
		scanf(" %d", &input);
		um[input]++;
	}

	scanf(" %d", &M);
	for (int i = 0, input; i < M; i++) {
		scanf(" %d", &input);
		printf("%d ", um[input]);
	}

	return 0;
}