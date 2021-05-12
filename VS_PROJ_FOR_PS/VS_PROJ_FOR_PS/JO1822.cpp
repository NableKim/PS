#include <cstdio>
using namespace std;

#define DIV 1000

int d[1000001];	// d[n] : n일자에 태어난 벌레 수 
int cnt;		// 전체 벌레 수
int parent;		// 성충 수

int main() {

	freopen("Text.txt", "r", stdin);

	// 입력
	int a, b, c, N;
	scanf(" %d %d %d %d", &a, &b, &c, &N);

	// 초기값
	d[0] = 1;
	d[a] = 1;
	cnt = 2;	// (a 일자 기준) 성체 1, 아기 1
	parent = 1;	// (a 일자 기준) 성체 1

	// a+1 ~ N일자 까지
	int t = a+1;
	while (t <= N) {
		// t일자 기준

		// step 1. 노화로 인한 벌레 수 감소
		if (t >= c)
			cnt -= d[t - c] % DIV;

		// step 2. 새로 번식할 수 있는 성체수 증가
		parent += d[t - a] % DIV;

		// step 3. 더 이상 번식할 수 없는 성체수 감소
		if(t>=b)
			parent -= d[t - b] % DIV;

		// step 4. 번식할 수 있는 성체 수 만큼 번식
		d[t] = parent%DIV;
		cnt += parent % DIV;

		t++;
	}

	printf("%d", cnt%DIV);

	return 0;
}