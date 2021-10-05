// �ð����⵵ : O(N*logN)

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_NUM 4000001

bool isntPrime[MAX_NUM];

int main() {

	int N;
	scanf(" %d", &N);

	// N������ ������ �Ҽ� ���� - �����佺�׳׽��� ü
	for (int i = 2; i * i <= N; i++) {		// O(��ƮN)
		for (int j = 2; j * i <= N; j++)	// O(N)
			isntPrime[i * j] = true;
	}

	vector<int> prime; // ������ �Ҽ��� ��� ����
	for (int i = 2; i <= N; i++) {	// O(N)
		if (!isntPrime[i])
			prime.push_back(i);
	}

	int answer = 0;
	int pSize = prime.size();	// N ������ �Ҽ� ����

	int left, right, sum;
	sum = left = right = 0;

	// �������͸� �̿��� A�������� B���������� ������ ���ϱ�
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