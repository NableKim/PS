/*
한쪽 방향에서 시작해서 다음 값을 확인 후, 
더 높은 기둥이 나오는지 or 낮은 기둥이 나오는지에 따라 값을 다르게 누적하는 방식
*/

#include <cstdio>
using namespace std;

int map[1002];

int main() {

	//freopen("Text.txt", "r", stdin);

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
	int turn = map[left]>map[right]? 1: 0;

	int sum = map[left];
	if (left != right)
		sum += map[right];

	while (right-left>1) {
		if (turn == 0) {
			if (map[left] >= map[left + 1])
				map[left + 1] = map[left];
			left++;
			sum += map[left];
		}
		else {
			if (map[right-1] <= map[right])
				map[right-1] = map[right];
			right--;
			sum += map[right];
		}

		turn = map[left] > map[right] ? 1 : 0;
	}

	printf("%d", sum);

	return 0;
}