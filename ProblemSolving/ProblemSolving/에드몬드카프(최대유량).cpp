/*
* 에드몬드 카프 알고리즘 == 최대유량
그래프 상에서 노드 간 흐를 수 있는 용량 정보가 간선으로 표현되어 있다.
이때, 노드 A에서 출발하여 노드 B까지 흐를 수 있는 최대 용량은 얼마인가?

시간복잡도 : O(VE^2)

참고) https://m.blog.naver.com/ndb796/221237111220
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_NODE 100
#define INF 10000000

using namespace std;

int Cap[MAX_NODE][MAX_NODE];	// A에서 B로 흐를 수 있는 용량
int Flow[MAX_NODE][MAX_NODE];	// 현재까지 A에서 B로 흐르는 유량
int D[MAX_NODE];				// 방문 체크 배열, 어느 지점에서 index 노드로 진입한건지 저장
vector<int> Edge[MAX_NODE];		// 간선 정보를 저장할 인접 리스트
int maximumFlow;	// 최대 유량 수

void maxFlow(int start, int end) {

	// start -> end 로 갈 수 있는 모든 경로에 대해 해주기
	while (1) {


		// 1. BFS를 사용하여 start -> end 에 이르는 경로를 D배열에 저장
		fill(D, D + MAX_NODE, -1);

		queue<int> q;
		q.push(start);
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (int i = 0; i < Edge[node].size(); i++) {
				int nextNode = Edge[node][i];
				// node -> nextNode로 흐를 수 있는 잔여량이 있다면
				if (D[nextNode] == -1 && Cap[node][nextNode] - Flow[node][nextNode] > 0) {
					q.push(nextNode);
					D[nextNode] = node;
					if (nextNode == end) break;	// start -> end 경로에 도달한 경우
				}
			}
		}

		// start -> end의 경로를 모두 찾은 경우
		if (D[end] == -1) break;

		// 2. 찾은 경로 상에서 흐를 수 있는 최대 용량을 계산
		int flow = INF;
		for (int i = end; i != start; i = D[i]) {
			int parentNode = D[i];
			flow = min(flow, Cap[parentNode][i] - Flow[parentNode][i]);
		}

		// 3. 위에서 찾은 최대 용량을 Flow 배열에 업데이트. 음의 유량도 반영
		for (int i = end; i != start; i = D[i]) {
			int parentNode = D[i];
			Flow[parentNode][i] += flow;
			Flow[i][parentNode] -= flow;
		}

		// 4. 정답 갱신
		maximumFlow += flow;
	}
}


int main() {
	Edge[1].push_back(2);
	Edge[1].push_back(2);
	Cap[1][2] = 12;

	Edge[1].push_back(4);
	Edge[4].push_back(1);
	Cap[1][4] = 11;

	Edge[2].push_back(3);
	Edge[3].push_back(2);
	Cap[2][3] = 6;

	Edge[2].push_back(4);
	Edge[4].push_back(2);
	Cap[2][4] = 3;

	Edge[2].push_back(5);
	Edge[5].push_back(2);
	Cap[2][5] = 5;

	Edge[2].push_back(6);
	Edge[6].push_back(2);
	Cap[2][6] = 9;

	Edge[3].push_back(6);
	Edge[6].push_back(3);
	Cap[3][6] = 8;

	Edge[4].push_back(5);
	Edge[5].push_back(4);
	Cap[4][5] = 9;

	Edge[5].push_back(3);
	Edge[3].push_back(5);
	Cap[5][3] = 3;

	Edge[5].push_back(6);
	Edge[6].push_back(5);
	Cap[5][6] = 4;

	maxFlow(1, 6);
	printf("%d", maximumFlow);
	return 0;
}

