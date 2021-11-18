/*
�����佺�׳׽��� ü�� �̿��� Ư�� ������ �Ҽ����� ���س���
�־��� ���� N�� �� ���� ������ �ɰ�����, �ɰ� �� ���� ��� �Ҽ����� �Ǵ��ؼ� ������ ������Ŵ
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