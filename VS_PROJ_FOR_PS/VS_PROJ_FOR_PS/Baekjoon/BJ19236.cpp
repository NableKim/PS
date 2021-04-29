#include <cstdio>
#include <cstring>
using namespace std;

struct FISH {
	int y, x, d;	// 좌표, 방향
	bool e;	// 잡아먹혔는가
};

int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int map[4][4] = { 0, };	// 각 좌표에 존재하는 물고기의 번호
FISH F[17] = { 0, };	// 물고기 정보
int answer;

char aaa(int d) {
	
	switch (d) {
	case 1:
		return '↑';
	case 2:
		return '↖';
	case 3:
		return '←';
	case 4:
		return '↙';
	case 5:
		return '↓';
	case 6:
		return '↘';
	case 7:
		return '→';
	case 8:
		return '↗';
	}
}

void print_map(int map[][4], int i) {
	printf("%d 번째 : \n", i);
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			printf(" %d", map[y][x]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void print_map2(int map[][4], int i, FISH* F) {
	printf("%d 번째 : \n", i);
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			printf(" %d", F[map[y][x]].d);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void simulation(int sy, int sx, int sd, int ss) {
	
	if (answer < ss)
		answer = ss;

	// 1번 물고기부터 이동
	for (int i = 1; i < 17; i++) {
		// 잡아먹혔다면 스킵
		if (F[i].e)
			continue;

		int cy = F[i].y;
		int cx = F[i].x;
		int cd = F[i].d;

		// 움직일 수 있는 공간을 찾겠지
		for (int k = 0; k < 8; k++) {
			// 다음 방향을 찾고
			int nd = cd + k;
			if (nd >= 9)
				nd -= 8;

			// i번째 물고기의 다음 위치 탐색
			int ny = cy + dy[nd];
			int nx = cx + dx[nd];

			// 범위를 벗어나거나
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
				continue;

			// 상어가 위치하고 있으면
			if (map[ny][nx] == -1)
				continue;
		
			// 빈칸이라면 단순 이동
			if (map[ny][nx] == 0) {
				map[cy][cx] = 0; // 현재 물고기의 위치를 비우기
				F[i].y = ny;	// i번째 물고기의 위치를 갱신
				F[i].x = nx;
				F[i].d = nd;
				map[ny][nx] = i;	// ny,nx 좌표에 i번째 물고기가 존재
				break;
			}
			// 다른 물고기가 있다면
			else if (map[ny][nx] != 0) {
				// 물고기 swap

				// i번째 물고기의 좌표 정보 업데이트
				F[map[cy][cx]].y = ny;
				F[map[cy][cx]].x = nx;
				F[map[cy][cx]].d = nd;

				// 교체당하는 물고기의 좌표 업데이트
				F[map[ny][nx]].y = cy;
				F[map[ny][nx]].x = cx;
				
				// 자리 바꿈 당하는 물고기 번호
				int tmp = map[ny][nx];
				map[ny][nx] = map[cy][cx];
				map[cy][cx] = tmp;
				break;
			}
		}
	}

	//print_map(map, 0);
	//print_map2(map, 0, F);

	// 상어 이동
	for (int k = 1; k <= 3; k++) {
		int ny = sy + k*dy[sd];
		int nx = sx + k*dx[sd];

		//printf("(%d %d)에서 (%d %d)로 \n", sy, sx, ny, nx);

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
			break;

		int map_bk[4][4];
		FISH F_bk[17];

		// 현재 정보 백업
		memcpy(map_bk, map, sizeof(map));
		memcpy(F_bk, F, sizeof(F));
		
		if (map[ny][nx] != 0) {
			int nextFish = map[ny][nx];
			map[sy][sx] = 0;	
			F[nextFish].e = true;
			map[ny][nx] = -1;	// 상어 다음 위치

			simulation(ny, nx, F[nextFish].d, ss + nextFish);

			// 원복
			memcpy(map, map_bk, sizeof(map));
			memcpy(F, F_bk, sizeof(F));
		}
	}
}

int main() {

	freopen("Text.txt", "r", stdin);

	

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			int n, d;
			scanf(" %d %d", &n, &d);
			map[y][x] = n;
			F[n] = { y, x, d, false };
		}
	}

	int sy, sx;	// 상어 최초 위치
	int ss;		// 상어가 잡아먹은 물고기번호 누적값
	int sd;		// 상어 방향

	// 0,0 위치의 물고기를 잡아먹고
	sy = sx = 0;
	ss = map[0][0];
	sd = F[map[0][0]].d;
	F[map[0][0]].e = true;	// 물고기 잡아먹힘 표시
	map[0][0] = -1;	// 좌표 상에 물고기 없애기, 상어가 위치함을 표시

	simulation(sy, sx, sd, ss);

	printf("%d", answer);

	return 0;
}