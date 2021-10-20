/*
*** 1�� �������� N�� ���������� �ִ� �Ÿ� ���ϱ�. ���⼭ �ִ� �Ÿ��� �ּ� ������ ���� ***
���� ���� ���� ���� ����
1�� ������ ���������� bfs Ž�� ����
ť�� ���� ������ ���� ������ ����
���� �������� ���µ� �䱸�Ǵ� �ּ� ���� ������Ʈ
bfs Ž�� ť�� ������� ������ �Ʒ� ���� �ݺ�
	ť���� �ϳ� ������
	���� ���� ����(A)�� ������ �ٸ� ����(B)�� ã��
	���� ����(B)���� �䱸�Ǵ� �������� ���� ����(A)������ ������ ��
	�� ū ���ڰ� ���� ����(NL)�� ��
	���� �������� �䱸�Ǵ� �ּ� ������(BL)�� ������ ���� ������(NL)�� ��
	BL������ NL���� �� ������
		BL�� ����
		ť�� ����
N�� �������� �䱸�Ǵ� �ּ� ������ ����
���� �������� +1�� �ؼ� �̸� ������ �����ϱ�
�ռ� ���� ������ �̻��� �ּ� �Ҽ� ���ϱ�
���� ���
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
			
			// ���� ü�������� ���鼭 �󸶸�ŭ ������ �ö���ϴ°�
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