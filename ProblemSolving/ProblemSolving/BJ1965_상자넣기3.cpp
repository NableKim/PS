/*
이분탐색을 활용한 LIS 문제풀이
*/

#include <cstdio>
#include <vector>
using namespace std;

#define BOX_NUM 1000

int B[BOX_NUM];
vector<int> lis;

int upper_bound(int left, int right, int target) {

	if (lis.empty())
		return -1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (target <= lis[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right + 1;
}

int main() {

	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
		scanf(" %d", &B[i]);

	for (int i = 0; i < N; i++) {
		int idx = upper_bound(0, lis.size()-1, B[i]);

		if (idx == -1)
			lis.push_back(B[i]);
		else if (idx >= lis.size())
			lis.push_back(B[i]);
		else
			lis[idx] = B[i];
	}

	printf("%d", lis.size());

	return 0;
}