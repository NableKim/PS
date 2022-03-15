/*
i = 1~10000���� �Ʒ��� ������ �ݺ�
	j�� 10000�����϶����� �Ʒ� ������ �ݺ�
		j�� j�� �ڸ������� ���� ����
		�� ���� �����ڰ� �ִ°Ŵϱ� �޸�
		j���� ���� ���� ������ ������Ʈ
10000������ �����ڰ� ���� ���� ���
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