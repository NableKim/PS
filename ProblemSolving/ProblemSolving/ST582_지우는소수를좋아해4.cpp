/*
*** 1번 정점에서 N번 정점까지의 최단 거리 구하기. 여기서 최단 거리는 최소 레벨을 말함 ***
정점 간의 간선 정보 저장
1번 정점을 시작점으로 bfs 탐색 시작
큐에 시작 정점과 현재 레벨을 삽입
현재 정점까지 오는데 요구되는 최소 레벨 업데이트
bfs 탐색 큐가 비어있을 때까지 아래 행위 반복
	큐에서 하나 꺼내고
	꺼낸 현재 정점(A)과 인접한 다른 정점(B)을 찾기
	다음 정점(B)까지 요구되는 레벨값과 현재 정점(A)에서의 레벨값 비교
	더 큰 숫자가 다음 레벨(NL)이 됨
	다음 정점에서 요구되는 최소 레벨값(BL)과 위에서 구한 레벨값(NL)을 비교
	BL값보다 NL값이 더 작으면
		BL값 갱신
		큐에 삽입
N번 정점에서 요구되는 최소 레벨값 리턴
구한 레벨값에 +1를 해서 미만 조건을 만족하기
앞서 구한 레벨값 이상의 최소 소수 구하기
정답 출력
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_NODE 10001
#define INF 100000000000001
struct E {
	int end, cost;
};

int N, M;
vector<E> v[MAX_NODE];
long long visited[MAX_NODE];

int bfs() {
	memset(visited, INF, sizeof(visited));
	
	queue<E> q;
	q.push({ 1, 0 });
	visited[1] = 0;

	while (!q.empty()) {
		E node = q.front(); q.pop();

		for (int k = 0; k < v[node.end].size(); k++) {
			int nextNode = v[node.end][k].end;
			int cost = v[node.end][k].cost;
			
			// 다음 체육관으로 가면서 얼마만큼 레벨이 올라야하는가
			int nextLevel = cost < node.cost ? node.cost : cost;

			if ((long long)nextLevel < visited[nextNode]) {
				visited[nextNode] = (long long)nextLevel;
				q.push({ nextNode, nextLevel });
			}
		}
	}

	return visited[N];
}

bool isPrime(int number) {
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	//freopen("Text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int answer = bfs();
	
	answer++;
	while (!isPrime(answer))
		answer++;
	cout << answer;

	return 0;
}