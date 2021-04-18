#include <cstdio>
#include <vector>
using namespace std;

struct C {
	bool e;	// 로봇 존재 유무
	int d;	// 내구도
};

C c[200];

int main() {

	int N, K;

	scanf(" %d %d", &N, &K);

	for (int i = 0, input; i < 2 * N; i++) {
		scanf(" %d", &input);
		c[i] = { false, input };	// i번째 컨베이벨트 정보를 저장
	}
	
	int t = 1;
	while (1) {
		// 컨베이어벨트 굴리기
		C tmp = c[2 * N - 1];
		for (int i = 2 * N - 1; i > 0; i--) {
			c[i] = c[i - 1];
		}
		c[0] = tmp;
		c[N - 1].e = false;

		// 로봇 전진
		for (int i = N-2; i >= 0; i--) {
			// 전진 가능하다면
			if (c[i].e && !c[i + 1].e && c[i+1].d > 0) {
				c[i].e = false;
				c[i + 1].e = true;
				c[i + 1].d--;
			
				// 떨어지는 위치라면
				if (i == N - 2)
					c[i + 1].e = false;
			}
		}

		// 맨처음 위치에 로봇 없으면 올리기
		if (!c[0].e && c[0].d>0) {
			c[0].e = true;
			c[0].d--;
		}

		int cnt = 0;
		// 내구도 0인거 갯수 세기
		for (int i = 0; i < 2 * N; i++) {
			if (c[i].d == 0)
				cnt++;
		}

		if (cnt >= K)
			break;

		t++;
	}

	printf("%d", t);

	return 0;
}