#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N;
int map[16][16];
vector<int> pick;
int answer = 987654321;

void dfs(int depth) {

	// N/2개의 재료를 구했음
	if (pick.size() == N / 2) {
		bool A[16] = { false };
		int sum1 = 0;
		for (int i = 0; i < N / 2; i++) {
			int a = pick[i];
			A[a] = true;
			for (int j = 0; j < N / 2; j++) {
				int b = pick[j];
				sum1 += map[a][b];
			}
		}

		// B 음식 재료 구하기
		vector<int> pickB;

		for (int i = 0; i < N; i++) {
			if (!A[i])
				pickB.push_back(i);
		}

		int sum2 = 0;
		for (int i = 0; i < N / 2; i++) {
			int a = pickB[i];
			for (int j = 0; j < N / 2; j++) {
				int b = pickB[j];
				sum2 += map[a][b];
			}
		}

		answer = abs(sum1 - sum2) < answer ? abs(sum1 - sum2) : answer;

		return;
	}

	for (int i = depth; i < N; i++) {
		pick.push_back(i);
		dfs(i + 1);
		pick.pop_back();
	}
}


int main() {
	// N개 중에 N/2개 뽑고
	// 이때 A, B 음식에 대한 총 시너지 양을 구하기
	// 두 차이를 구하고 // 최소값 찾기
	
	//freopen("Text.txt", "r", stdin);

	int testcase;

	scanf(" %d", &testcase);

	for (int tc = 1; tc <= testcase; tc++) {
		pick.clear();
		answer = 987654321;

		scanf(" %d", &N);

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++) {
				scanf(" %d", &map[y][x]);
				;
			}
		}

		dfs(0);

		printf("#%d %d\n", tc, answer);
	}

	

	return 0;
}