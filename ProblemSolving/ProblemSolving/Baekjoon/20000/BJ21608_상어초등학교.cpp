#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_NUM 21
#define MAX_NUM_SQ MAX_NUM*MAX_NUM

int map[MAX_NUM][MAX_NUM];	// 자리배치도
bool like[MAX_NUM_SQ][MAX_NUM_SQ];// 선호도

// 상하좌우 4방향
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

struct Info {
	int y, x, likeCnt, emptyCnt;
};

bool cmp(Info a, Info b) {
	if (a.likeCnt == b.likeCnt) {
		if (a.emptyCnt == b.emptyCnt) {
			if (a.y == b.y)
				return a.x < b.x;
			return a.y < b.y;
		}
		return a.emptyCnt > b.emptyCnt;
	}
	return a.likeCnt > b.likeCnt;
}

vector<Info> getSeatCandidate(int studentNo, int N) {

	vector<Info> v;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			if (map[y][x] != 0) continue;

			int emptyCnt = 0;
			int likeCnt = 0;

			for (int k = 0; k < 4; k++) {

				int ny = y + dy[k];
				int nx = x + dx[k];

				// 범위를 벗어나는 경우
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;
				
				// 비어있는 경우
				if (map[ny][nx] == 0) {
					emptyCnt++;
					continue;
				}

				int neighborStudentNo = map[ny][nx];
				if (like[studentNo][neighborStudentNo]) 
					likeCnt++;
			}

			v.push_back({ y, x, likeCnt, emptyCnt });
		}
	}

	return v;
}

int getScore(int cnt) {
	if (cnt == 0)
		return 0;
	else if (cnt == 1)
		return 1;
	else if (cnt == 2)
		return 10;
	else if (cnt == 3)
		return 100;
	else if (cnt == 4)
		return 1000;
	else
		return 0;
}

int getLikeCnt(int y, int x, int N) {

	int studentNo = map[y][x];
	int likeCnt = 0;
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];

		// 범위를 벗어나는 경우
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		int neighborStudentNo = map[ny][nx];
		if (like[studentNo][neighborStudentNo])
			likeCnt++;
	}

	return getScore(likeCnt);

}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf(" %d", &N);

	// 선호 관계 입력받기
	for (int i = 0; i < N*N; i++) {
		int y;
		scanf(" %d", &y);

		for (int j = 0, x; j < 4; j++) {
			scanf(" %d", &x);
			like[y][x] = true;	//y가 x를 선호
		}
	
		// y가 앉을 자리 후보 찾기
		vector<Info> v = getSeatCandidate(y, N);
		
		sort(v.begin(), v.end(), cmp);

		Info seat = v[0];

		map[seat.y][seat.x] = y;
	}

	int answer = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			answer += getLikeCnt(y, x, N);
		}
	}

	printf("%d", answer);

	return 0;
}
