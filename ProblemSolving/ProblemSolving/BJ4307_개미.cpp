/*
두 개미가 충돌해서 방향이 바뀌는 행위를 개미가 서로를 통과한다고 생각하는 것이 포인트.
결국 한 개미가 끝까지 가는데까지 걸리는 시간값을 놓고 생각하면 됨.
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

			// n1이 n2보다 큰 값을 가지도록 하기
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