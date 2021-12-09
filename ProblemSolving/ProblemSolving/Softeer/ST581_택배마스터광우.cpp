/*
라인의 순서를 정한다(순열)
정해진 라인의 순서에 따라 아래 행위를 반복
	K번 일 시뮬레이션 시행
	시뮬레이션의 결과값과 그 이전의 결과값을 비교 후 더 작으면 갱신
정답 출력
*/

#include<iostream>
using namespace std;

int N, M, K;
int W[10];
int answer = 987654321;

int simulation() {

	int idx = 0;
	int k = 0;

	int basket = 0;
	int totalWeight = 0;
	while (k < K) {
		if (basket + W[idx] <= M) {
			basket += W[idx];
			idx = (idx + 1) % N;
		}
		else {
			k++;
			totalWeight += basket;
			basket = 0;
		}
	}
	
	return totalWeight;
}

void swap(int a, int b) {
	int tmp = W[a];
	W[a] = W[b];
	W[b] = tmp;
}

void dfs(int depth) {
	if (depth == N) {

		int totalWeight = simulation();
		answer = totalWeight < answer ? totalWeight : answer;
		
		return;
	}

	for (int i = depth; i < N; i++) {
		swap(depth, i);
		dfs(depth + 1);
		swap(depth, i);
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> W[i];

	dfs(0);

	cout << answer;

	return 0;
}