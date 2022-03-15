// 시간복잡도 : O(N*logN)

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
	for (int i = 2; i * i <= N; i++) {		// O(루트N)
		for (int j = 2; j * i <= N; j++)	// O(N)
			isntPrime[i * j] = true;
	}

	vector<int> prime; // 추출한 소수가 담긴 벡터
	for (int i = 2; i <= N; i++) {	// O(N)
		if (!isntPrime[i])
			prime.push_back(i);
	}

	int answer = 0;
	int pSize = prime.size();	// N 이하의 소수 갯수

	int left, right, sum;
	sum = left = right = 0;

	// 투포인터를 이용한 A지점부터 B지점까지의 구간합 구하기
	while (1) {						// O(N)
		if (sum < N) {
			if (right >= pSize) break;
			sum += prime[right++];
			continue;
		}
		else if (sum == N)
			answer++;
		sum -= prime[left++];
	}

	printf("%d", answer);
	return 0;
}