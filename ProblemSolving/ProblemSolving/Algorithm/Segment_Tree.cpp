#include <cstdio>
#include <vector>
#include <iostream>
#define NUMBER 12

using namespace std;

int a[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };	// �־��� ������
int tree[NUMBER * 4];					// ���׸�Ʈ Ʈ��

// ������ �迭 a�� ������ ���׸�Ʈ Ʈ���� �����ϴ� �Լ�
// start :���� �ε���, end : �� �ε���, node : ���׸�Ʈ Ʈ�� �� ����ȣ
int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node*2) + init(mid + 1, end, node * 2 + 1);
}

// ���׸�Ʈ Ʈ���� ������ ���� ���� ���ϴ� �Լ�
// start~end ������ ������ node��° ��忡�� left~right ������ �� ���ϱ�
int sum(int start, int end, int node, int left, int right) {
	
	// ������ �ƿ� ����ų�
	if (start > right || end < left) return 0;
	
	// ������ �����ϰų�
	if (left <= start && end <= right) return tree[node];

	// ���� �ȿ� �ְų�
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// index��° node�� diff ��ŭ �� ��ȭ�Կ� ���� ���׸�Ʈ Ʈ������ �������ֱ� ���� �Լ�
void update(int start, int end, int node, int index, int diff) {

	// ���� �ۿ� �ִ� ���
	if (index < start || index > end) return;
	
	tree[node] += diff;	// ������ ����

	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid+1, end, node * 2 + 1, index, diff);
}


int main() {

	init(0, NUMBER - 1, 1);
	
	cout << "0���� 11��° �����ͱ����� ���� �� : " << sum(0, NUMBER - 1, 1, 0, 11) << "\n";

	update(0, NUMBER - 1, 1, 5, -3);

	cout << "0���� 11��° �����ͱ����� ���� �� : " << sum(0, NUMBER - 1, 1, 0, 11) << "\n";

	cout << "0���� 3��° �����ͱ����� ���� �� : " << sum(0, NUMBER - 1, 1, 0, 3) << "\n";

	return 0;
}