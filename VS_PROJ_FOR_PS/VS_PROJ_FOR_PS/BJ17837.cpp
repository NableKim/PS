#include <cstdio>
using namespace std;

int N, K;	// 판 크기, 말의 개수

int map[12][12];

struct HORSE {
	int y, x, d, top, bottom;
};

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
HORSE H[11];

// ny, nx 좌표 상에 위치한 제일 꼭대기 말
int getTop(int ny, int nx) {

	int candi = -1;

	// K번째 말까지 뒤져서 ny, nx 자리에 있는 말 하나 찾기
	for (int i = 1; i <= K; i++) {
		if (H[i].y == ny && H[i].x == nx) {
			candi = i;
			break;
		}
	}

	if (candi == -1)
		return -1;

	int top = candi;
	while (H[top].top != -1) {
		top = H[top].top;
	}

	return top;
}


int getNumber(int ny, int nx) {

	int cnt = 0;
	for (int i = 1; i <= K; i++) {
		if (H[i].y == ny && H[i].x == nx) {
			cnt++;
		}
	}

	return cnt;
}

void flip(int i, int top) {
	// i번째 말 위로 다른 말들이 존재하지 않는다면
	if (top == -1)
		return;
	
	// i번째 말과 그 아래에 있는 말의 연결이 끊음
	int bot = H[i].bottom;
	if (bot != -1) {
		H[bot].top = -1;
		H[i].bottom = -1;	// i번째 말 아래 정보 없애기
	}

	// 뒤집기 시작
	int bot2 = top;
	while (bot2 != -1) {
		int tmp = H[bot2].top;
		H[bot2].top = H[bot2].bottom;
		H[bot2].bottom = tmp;
		bot2 = H[bot2].top;	// 그 아래 노드를 탐색
	}

	// 뒤집기가 시작된 부분과 그 아래 말과의 연결 만들기
	if (bot != -1) {
		H[top].bottom = bot;
		H[bot].top = top;
	}
}

// i번째 말부터 위의 말들을 다음 위치로 이동
void move(int i, int ny, int nx) {

	// i번째 말 아래에 있는 말의 top을 비우기
	int bot = H[i].bottom;
	if (bot != -1) {
		H[bot].top = -1;
	}
	
	// 다음 위치에 맨 꼭대기 말 번호
	int top = getTop(ny, nx);

	if (top == -1) {
		// i번째 말을 다음 위치로 옮기고
		H[i].bottom = -1;
		H[i].y = ny;
		H[i].x = nx;

		// i번째 말 위에 있는 말들도 다음위치로 옮김
		int top2 = H[i].top;
		while (top2 != -1) {
			H[top2].y = ny;
			H[top2].x = nx;
			top2 = H[top2].top;
		}
	}
	// 다음 위치에 말이 이미 존재한다면
	else {
		// 다음 위치 맨 위 말의 top 정보에 i를 저장
		H[top].top = i;

		// i번째 말의 정보 갱신
		H[i].bottom = top;
		H[i].y = ny;
		H[i].x = nx;

		// i번째 말 위에 있는 말들도 다음위치로 옮김
		int top2 = H[i].top;
		while (top2 != -1) {
			H[top2].y = ny;
			H[top2].x = nx;
			top2 = H[top2].top;
		}
	}
}

int main() {

	//freopen("Text.txt", "r", stdin);

	scanf(" %d %d", &N, &K);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
			scanf(" %d", &map[y][x]);
	}

	for (int i = 1; i <= K; i++) {
		int y, x, d;
		scanf(" %d %d %d", &y, &x, &d);
		H[i] = { y-1, x-1, d - 1, -1, -1 };
	}

	int t = 1;
	while (t<=1000) {

		// 1번말부터 K번말까지 이동
		bool flag = false;
		for (int i = 1; i <= K; i++) {
			//printf("%d\n", i);
			int cy = H[i].y;
			int cx = H[i].x;
			int cd = H[i].d;

			int ny = cy + dy[cd];
			int nx = cx + dx[cd];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
				// 방향을 바꾸고 다시 시도
				if (!flag) {
					flag = true;
					H[i].d = (H[i].d % 2 == 0) ? cd + 1 : cd - 1;	// 반대방향
					i--;
					continue;
				}
			}
			// 빈칸
			else if (map[ny][nx] == 0) {
				// i번째 말부터 위에 있는 말들을 모두 다음 위치로 이동
				move(i, ny, nx);
			}
			// 빨간색
			else if(map[ny][nx] == 1) {
				// 현재 위치에서의 꼭대기 말 찾기
				int top = getTop(cy, cx);
				// i번째 말들을 뒤집기
				flip(i, top);
				// 새로운 꼭대기 말부터 위에 있는 말들을 모두 다음 위치로 이동
				move(top, ny, nx);
			}
			// 파란색(빈칸과 로직 동일)
			else {
				// 방향을 바꾸고 다시 시도
				if (!flag) {
					flag = true;
					H[i].d = (H[i].d % 2 == 0) ? cd + 1 : cd - 1;	// 반대방향
					i--;
					continue;
				}
			}
			flag = false;

			// 말이 4개 쌓였다면 종료
			if (getNumber(ny, nx) >= 4) {
				printf("%d", t);
				return 0;
			}
		}
		t++;
	}

	printf("-1");

	return 0;
}