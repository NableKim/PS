#include <cstdio>
using namespace std;

int N;
int A[500][500];	// 격자
int dir = 0;	// 좌 하 우 상
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int cy, cx;
int answer = 0;

int map[4][5][5] = {
	{
		{0,0,2,0,0},
		{0,10,7,1,0},
		{5,0,0,0,0},
		{0,10,7,1,0},
		{0,0,2,0,0}
	},
	{
		{0,0,0,0,0},
		{0,1,0,1,0},
		{2,7,0,7,2},
		{0,10,0,10,0},
		{0,0,5,0,0}
	},
	{
		{0,0,2,0,0},
		{0,1,7,10,0},
		{0,0,0,0,5},
		{0,1,7,10,0},
		{0,0,2,0,0}
	},
	{	{0,0,5,0,0},
		{0,10,0,10,0},
		{2,7,0,7,2},
		{0,1,0,1,0},
		{0,0,0,0,0}
	}
};

void print_map() {
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			printf("%d ", A[y][x]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void scatter_sand(int ny, int nx) {
	// 행렬 곱을 수행하는 로직이 필요

	// 5x5 행렬곱이 수행되어야하는데

	// ny, nx가 (2,2)가 되어 행렬곱을 수행후 원래 위치에 가산되어야함
	int moving = 0;	// 움직인 모래 총량
	int out = 0;	// 격자 밖으로 이동한 모래 총량

	for (int y = ny-2; y <= ny+2; y++)
	{
		for (int x = nx-2; x <= nx+2; x++)
		{
			int sand = A[ny][nx] * map[dir][y - (ny - 2)][x - (nx - 2)] / 100;

			moving += sand;	// 움직인 모래 총량에 누적

			// 모래가 날라간 위치가 격자 밖이라면
			if (y < 0 || y >= N || x < 0 || x >= N)
				out += sand;
			else 
				A[y][x] += sand;	// 날라간 위치에 모래양 가산
		}
	}

	// 알파위치에 대해서
	int ay=ny, ax = nx;
	if (dir == 0)
		ax -= 1;
	else if (dir == 1)
		ay += 1;
	else if (dir == 2)
		ax += 1;
	else
		ay -= 1;

	int r = A[ny][nx] - moving;	// 움직이고 남은 모래 총량

	// 밖으로 나갔다면
	if (ay < 0 || ay >= N || ax < 0 || ax >= N)
		out += r;
	else
		A[ay][ax] += r;

	A[ny][nx] = 0;

	//print_map();
	//printf("%d\n", out);
	//printf("============================\n");
	answer += out;
}

int main() {

	freopen("Text.txt", "r", stdin);
	
	scanf(" %d", &N);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
			scanf(" %d", &A[y][x]);
	}
	
	
	cy = N / 2;
	cx = N / 2;	// 현재 위치

	//cy = 2; cx = 1;

	int dis = 1, preDis = 1;	// 방향 전환까지 남은 거리
	bool flag = false;	// 방향 전환 후 거리를 증가시켜야하는가

	//scatter_sand(1, 1);
	while (1) {
		
		// 다음 위치
		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		// 모래 흩뿌리기
		scatter_sand(ny, nx);

		// 다음 위치가 (0,0)이라면 종료
		if (ny == 0 && nx == 0)
			break;

		// 방향 바꿔줘야하는지 검사
		dis--;
		if (dis == 0) {
			if (flag)
				preDis += 1;
			
			dis = preDis;
			flag = !flag;
			dir = (dir + 1) % 4;	// 방향 전환
		}

		// 다음 위치를 현재 위치로 설정
		cy = ny;
		cx = nx;
	}

	printf("%d", answer);



	return 0;
}