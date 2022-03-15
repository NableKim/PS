/*
재귀를 이용해 부분문제를 해결하여 큰 문제를 해결하려는 접근 방식 사용

1번째 장대에 있는 N개를 3번째 장대에 옮기려면
 1. N-1개를 2번 장대로 옮김
 2. 1개를 3번 장대로 옮김
 3. 2번 장대에 있는 N-1개를 3번 장대로 옮김
*/

#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;

// 판 몇개를 from에서 to로 옮기는 함수
int hanoi(int n, int from, int to, int tmp) {

	if (n == 1) {
		v.push_back({ from + 1, to + 1 });
		return 1;
	}

	// 맨 아래판을 옮기기 위해선 위에 n-1개를 다른 곳에 옮기고 가장 아래판을 목적지로 옮김
	// 그리고 나서 다른곳에 있던 n-1개 판을 목적지로 옮김
	return hanoi(n - 1, from, tmp, to) + hanoi(1, from, to, tmp) + hanoi(n - 1, tmp, to, from);
}


int main() {

	scanf(" %d", &N);

	printf("%d\n", hanoi(N, 0, 2, 1));
	
	for (int i = 0; i < v.size(); i++)
		printf("%d %d\n", v[i].first, v[i].second);

	return 0;
}