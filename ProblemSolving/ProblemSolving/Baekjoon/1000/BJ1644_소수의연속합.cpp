#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_NUM 4000001

bool isntPrime[MAX_NUM];

int main() {

	int N;
	scanf(" %d", &N);

	// N까지의 수에서 소수 추출 - 에라토스테네스의 체
	for (int i = 2; i * i <= N; i++) {
		for (int j = 2; j * i <= N; j++)
			isntPrime[i * j] = true;
	}

	vector<int> prime; // 추출한 소수가 담긴 벡터
	for (int i = 2; i <= N; i++) {
		if (!isntPrime[i])
			prime.push_back(i);
	}
	
	int answer = 0;
	int pSize = prime.size();	// N 이하의 소수 갯수

	// i번째 소수까지의 누적합 계산
	for (int i = 1; i < pSize; i++)	// 2, 3, 5, 7, ... ==> 2, 5, 10, 17, ...
		prime[i] += prime[i - 1];	

	// left를 기준으로 right 위치를 바꿔가며 연속된 수의 합이 N인지 확인
	for (int left = 0; left < pSize; left++) {

		int right = pSize - 1;
		int preRight = left;

		// 이분탐색 응용
		while (1) {
			// left~right 구간까지의 소수 합
			int sum = prime[right];
			if (left != 0)
				sum -= prime[left - 1];

			int tmp = right;

			if (sum == N) {
				answer++;
				break;
			}
			else if(sum < N) {
				right = (preRight + right) / 2;
			}
			else {
				int mid = (left + right) / 2;
				preRight = right;
				right = mid;
			}

			if (tmp == right)
				break;
		}
	}

	printf("%d", answer);
	return 0;
}

/*
for (int k = 1; k <= pSize; k++) {
		for (int end = pSize - 1; end >= k - 1; end--) {
			int start = end - k + 1;
			int sum = 0;
			for (int i = start; i <= end; i++) {
				sum += prime[i];
			}

			if (sum == N)
				answer++;
			else if (sum < N)
				break;
		}
	}
*/