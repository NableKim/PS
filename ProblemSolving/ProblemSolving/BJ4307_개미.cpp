/*
�� ���̰� �浹�ؼ� ������ �ٲ�� ������ ���̰� ���θ� ����Ѵٰ� �����ϴ� ���� ����Ʈ.
�ᱹ �� ���̰� ������ ���µ����� �ɸ��� �ð����� ���� �����ϸ� ��.
*/

#include <cstdio>
using namespace std;

int main() {

	//freopen("Text.txt", "r", stdin);

	int T;
	scanf(" %d", &T);

	for (int tc = 1; tc <= T; tc++) {
		
		int l, n;
		scanf(" %d %d", &l, &n);

		int maxVal1 = 0, maxVal2 = 0;
		for (int i = 0, input; i < n; i++) {
			scanf(" %d", &input);
			
			int n1 = l - input;
			int n2 = input;

			// n1�� n2���� ū ���� �������� �ϱ�
			if (n1 < n2) {
				int tmp = n1;
				n1 = n2;
				n2 = tmp;
			}

			maxVal1 = maxVal1 < n1 ? n1 : maxVal1;
			maxVal2 = maxVal2 < n2 ? n2 : maxVal2;
		}
		
		printf("%d %d\n", maxVal2, maxVal1);
	}
	

	return 0;
}