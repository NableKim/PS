/*
* ������ ī�� �˰��� == �ִ�����
�׷��� �󿡼� ��� �� �带 �� �ִ� �뷮 ������ �������� ǥ���Ǿ� �ִ�.
�̶�, ��� A���� ����Ͽ� ��� B���� �带 �� �ִ� �ִ� �뷮�� ���ΰ�?

�ð����⵵ : O(VE^2)

����) https://m.blog.naver.com/ndb796/221237111220
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_NODE 100
#define INF 10000000

using namespace std;

int Cap[MAX_NODE][MAX_NODE];	// A���� B�� �带 �� �ִ� �뷮
int Flow[MAX_NODE][MAX_NODE];	// ������� A���� B�� �帣�� ����
int D[MAX_NODE];				// �湮 üũ �迭, ��� �������� index ���� �����Ѱ��� ����
vector<int> Edge[MAX_NODE];		// ���� ������ ������ ���� ����Ʈ
int maximumFlow;	// �ִ� ���� ��

void maxFlow(int start, int end) {

	// start -> end �� �� �� �ִ� ��� ��ο� ���� ���ֱ�
	while (1) {


		// 1. BFS�� ����Ͽ� start -> end �� �̸��� ��θ� D�迭�� ����
		fill(D, D + MAX_NODE, -1);

		queue<int> q;
		q.push(start);
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (int i = 0; i < Edge[node].size(); i++) {
				int nextNode = Edge[node][i];
				// node -> nextNode�� �带 �� �ִ� �ܿ����� �ִٸ�
				if (D[nextNode] == -1 && Cap[node][nextNode] - Flow[node][nextNode] > 0) {
					q.push(nextNode);
					D[nextNode] = node;
					if (nextNode == end) break;	// start -> end ��ο� ������ ���
				}
			}
		}

		// start -> end�� ��θ� ��� ã�� ���
		if (D[end] == -1) break;

		// 2. ã�� ��� �󿡼� �带 �� �ִ� �ִ� �뷮�� ���
		int flow = INF;
		for (int i = end; i != start; i = D[i]) {
			int parentNode = D[i];
			flow = min(flow, Cap[parentNode][i] - Flow[parentNode][i]);
		}

		// 3. ������ ã�� �ִ� �뷮�� Flow �迭�� ������Ʈ. ���� ������ �ݿ�
		for (int i = end; i != start; i = D[i]) {
			int parentNode = D[i];
			Flow[parentNode][i] += flow;
			Flow[i][parentNode] -= flow;
		}

		// 4. ���� ����
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

