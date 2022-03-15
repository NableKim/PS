#include <cstdio>
using namespace std;

int s[100001];
int top = -1;

int main() {

	int K;
	scanf("%d", &K);

	int sum = 0;
	for (int i = 0, input; i < K; i++) {
		scanf(" %d", &input);

		if (input == 0 && top != -1) {
			sum -= s[top];
			top--;
		}
		else {
			s[++top] = input;
			sum += input;
		}
	}

	printf("%d", sum);

	return 0;
}