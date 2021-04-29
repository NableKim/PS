#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	unsigned long long N;
	int M;
	vector<int> v;

	scanf(" %llu %d", &N, &M);

	for (int i = 0, t; i < M; i++) {
		scanf(" %d", &t);
		v.push_back(t);
	}
	
	unsigned long long left = 1;
	unsigned long long right = 60000000000;
	unsigned long long end = 0;	// N명의 아이가 놀이기구 운행을 마친 시각

	while (left <= right) {
		unsigned long long mid = (left + right) / 2;

		// mid 시간까지 몇명이 놀이기구를 탈 수 있는가
		unsigned long long cnt = 0;
		for (int i = 0; i < M; i++)
			cnt += (mid / v[i]);

		printf("cnt : %llu\n", cnt);
		printf("mid : %llu\n", mid);

		if (cnt >= N) {
			end = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	printf("%llu\n", end);

	for (int i = M-1; i >= 0; i--)
	{
		if (end % v[i] == 0) {
			printf("%d", i + 1);
			break;
		}
	}

	return 0;
}