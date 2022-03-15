/*
��͸� �̿��� �κй����� �ذ��Ͽ� ū ������ �ذ��Ϸ��� ���� ��� ���

1��° ��뿡 �ִ� N���� 3��° ��뿡 �ű����
 1. N-1���� 2�� ���� �ű�
 2. 1���� 3�� ���� �ű�
 3. 2�� ��뿡 �ִ� N-1���� 3�� ���� �ű�
*/

#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;

// �� ��� from���� to�� �ű�� �Լ�
int hanoi(int n, int from, int to, int tmp) {

	if (n == 1) {
		v.push_back({ from + 1, to + 1 });
		return 1;
	}

	// �� �Ʒ����� �ű�� ���ؼ� ���� n-1���� �ٸ� ���� �ű�� ���� �Ʒ����� �������� �ű�
	// �׸��� ���� �ٸ����� �ִ� n-1�� ���� �������� �ű�
	return hanoi(n - 1, from, tmp, to) + hanoi(1, from, to, tmp) + hanoi(n - 1, tmp, to, from);
}


int main() {

	scanf(" %d", &N);

	printf("%d\n", hanoi(N, 0, 2, 1));
	
	for (int i = 0; i < v.size(); i++)
		printf("%d %d\n", v[i].first, v[i].second);

	return 0;
}