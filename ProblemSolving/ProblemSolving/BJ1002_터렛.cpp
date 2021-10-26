/*
�� ���� ������ ���ϴ� ����
1) ������ ���Ѱ��� ���
	- �� ���� �߽��� ������ ������ ���� ���� ������ ��
2) ������ 1���� ���
	- ����
	- ����
3) ������ 0���� ���
	- �� ���� �ָ� ������ ���
	- ���� ���� ū �� �ȿ� �� ������ �ʴ� ���
4) ������ 2���� ���
	1), 2), 3) ����� ������
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int answer = 0;

		// r2�� �� �������� �� ū ���� ������ ��
		if (r1 > r2) {
			int tmp = r1;
			r1 = r2;
			r2 = tmp;
		}

		int d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		
		if (x1 == x2 && y1 == y2 && r1 == r2)
			answer = -1;
		else if ((r1 + r2)*(r1 + r2) == d2 || d2 == (r2 - r1)*(r2-r1))
			answer = 1;
		else if ((r1 + r2)*(r1+r2) < d2 || d2 < (r2-r1)* (r2 - r1))
			answer = 0;
		else
			answer = 2;

		cout << answer << "\n";
	}

	return 0;
}