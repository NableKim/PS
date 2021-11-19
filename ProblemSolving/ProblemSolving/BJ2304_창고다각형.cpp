#include <cstdio>
using namespace std;

int map[1001];

int main() {

	int N;
	scanf("%d", &N);

	int minIdx = 1001;
	int maxIdx = 0;
	for (int i = 0, a, b; i < N; i++) {
		scanf(" %d %d", &a, &b);
		map[a] = b;

		minIdx = a < minIdx? a : minIdx;
		maxIdx = a > maxIdx? a : maxIdx;
	}

	int left = minIdx, right = maxIdx;
	
	int sum = map[left];
	if (left != right)
		sum += map[right];

	int turn = 0;
	int preLeft = left++;
	int preRight = right--;
	while (left <= right) {

		if (turn == 0) {
			if (map[preLeft] >= map[left]) {
				sum += map[preLeft];
				left++;
			}
			else {
				sum += map[left];
				preLeft = left++;
				turn ^= 1;
			}
		}
		else {
			if (map[right] <= map[preRight]) {
				sum += map[preRight];
				right--;
			}
			else {
				sum += map[right];
				preRight = right--;
				turn ^= 1;
			}
		}
	}

	printf("%d", sum);

	return 0;
}