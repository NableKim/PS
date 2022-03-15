/*
두 원의 교점을 구하는 문제
1) 교점이 무한개인 경우
	- 두 원의 중심이 같으며 반지름 길이 또한 동일할 때
2) 교점이 1개인 경우
	- 외접
	- 내접
3) 교점이 0개인 경우
	- 두 원이 멀리 떨어진 경우
	- 작은 원이 큰 원 안에 들어가 만나지 않는 경우
4) 교점이 2개인 경우
	1), 2), 3) 경우의 여집합
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

		// r2가 더 반지름이 더 큰 값을 갖도록 함
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