/*
***1�� ��带 ������ ������ ������ MST�� ����� ����***

�̹� �������� ���� ����Ǿ� �ִ� ������ ����
1��, �̹� ����Ǿ� �ִ� ���� ��ȣ�� ���� ������ ��尣 ���� ������ �ּ����� ����
ũ�罺Į �˰��� ����
	���� ����� ª�� �ͺ��� ������
	�� ���� �� ����Ŭ ���翩�� Ȯ��
	����Ŭ ������ �ȵȴٸ�
		�߰��� ���� ����(�� ����, ���) ����
		����Ŭ ������Ʈ
*/

#include <iostream>
#include <queue>
using namespace std;

#define NODE_NUM 1001

struct E {
	int a, b, c;
};

int N, M;
int parent[NODE_NUM];
int Edge[NODE_NUM][NODE_NUM];
vector<E> v;
priority_queue<E> pq;

bool operator<(E a, E b) {
	return a.c > b.c;
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);

	if (pa < pb)
		parent[pb] = pa;
	else
		parent[pa] = pb;
}

bool isSameParent(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);

	return (pa==pb);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		unionParent(a-1, b-1);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Edge[i][j];
			if (i >= j) continue;
			pq.push({ i, j, Edge[i][j] });
		}
	}

	while (!pq.empty()) {
		E front = pq.top();
		pq.pop();

		if (front.a == 0 || front.b ==0)
			continue;

		if (isSameParent(front.a, front.b))
			continue;

		unionParent(front.a, front.b);
		v.push_back(front);
	}
	
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i].c;

	cout << sum << " " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i].a+1 << " " << v[i].b+1 << "\n";

	return 0;
}