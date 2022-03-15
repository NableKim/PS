/*
666부터 1씩 증가시키면서 6이 연속으로 3번 이상 나오면 cnt증가
cnt가 입력받은 N이 되면 정답을 출력한다
*/

#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int number = 666;
	int cnt = 0;

	while (cnt != N) {

		int sixCnt = 0;
		int q = number;
		int r = q % 10;

		while (q != 0) {
			if (r == 6) {
				sixCnt++;
				if (sixCnt >= 3) {
					cnt++;
					break;
				}
			}
			else
				sixCnt = 0;

			q = q / 10;
			r = q % 10;
		}

		number++;
	}

	cout << number-1;

	return 0;
}