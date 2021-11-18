/*
에라토스테네스의 체를 이용한 특정 범위의 소수들을 구해놓고
주어진 숫자 N을 두 수의 합으로 쪼개가며, 쪼갠 두 수가 모두 소수인지 판단해서 갯수를 증가시킴
*/

#include <cstdio>
using namespace std;

#define MAX_NUM 1000000

bool isNotPrimeNumber[MAX_NUM + 1];

void getPrimeNumber() {

	isNotPrimeNumber[0] = isNotPrimeNumber[1] = true;

	for (int i = 2; i * i <= MAX_NUM; i++) {
		for (int j = 2; j * i <= MAX_NUM; j++)
			isNotPrimeNumber[i * j] = true;
	}
}

int main() {

	int T;
	scanf(" %d", &T);

	getPrimeNumber();

	for (int t = 0, N; t < T; t++) {
		
		int cnt = 0;

		scanf(" %d", &N);
		
		for (int i = 2; i + i <= N; i++) {
			int j = N - i;
			if (!isNotPrimeNumber[i] && !isNotPrimeNumber[j]) cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}