/*
i = 1~10000까지 아래의 과정을 반복
	j가 10000이하일때까지 아래 과정을 반복
		j와 j의 자릿수들의 합을 구함
		그 합은 생성자가 있는거니까 메모
		j값을 위에 구한 합으로 업데이트
10000이하의 생성자가 없는 숫자 출력
*/

#include <cstdio>
using namespace std;

#define MAX_NUM 10001

int check[MAX_NUM];

int getEachNumberSum(int number) {

	int sum = 0;
	while (1) {
		int q = number / 10;
		int r = number % 10;

		sum += r;

		if (q == 0)
			break;
		
		number = q;
	}
	return sum;
}

int main() {

	for (int i = 1; i < MAX_NUM; i++) {
		int j = i;
		while (1) {
			int nextJ = j + getEachNumberSum(j);
			
			if (nextJ >= MAX_NUM)
				break;

			check[nextJ] = true;
			j = nextJ;
		}
	}

	for (int i = 1; i < MAX_NUM; i++) {
		if (!check[i])
			printf("%d\n", i);
	}

	return 0;
}