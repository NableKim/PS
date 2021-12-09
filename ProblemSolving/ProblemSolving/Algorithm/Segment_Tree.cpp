#include <cstdio>
#include <vector>
#include <iostream>
#define NUMBER 12

using namespace std;

int a[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };	// 주어진 데이터
int tree[NUMBER * 4];					// 세그먼트 트리

// 데이터 배열 a를 가지고 세그먼트 트리를 생성하는 함수
// start :시작 인덱스, end : 끝 인덱스, node : 세그먼트 트리 내 노드번호
int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node*2) + init(mid + 1, end, node * 2 + 1);
}

// 세그먼트 트리를 가지고 구간 합을 구하는 함수
// start~end 구간을 가지는 node번째 노드에서 left~right 구간의 합 구하기
int sum(int start, int end, int node, int left, int right) {
	
	// 구간을 아예 벗어나거나
	if (start > right || end < left) return 0;
	
	// 구간을 포함하거나
	if (left <= start && end <= right) return tree[node];

	// 구간 안에 있거나
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// index번째 node가 diff 만큼 값 변화함에 따라 세그먼트 트리값을 갱신해주기 위한 함수
void update(int start, int end, int node, int index, int diff) {

	// 범위 밖에 있는 경우
	if (index < start || index > end) return;
	
	tree[node] += diff;	// 구간합 갱신

	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid+1, end, node * 2 + 1, index, diff);
}


int main() {

	init(0, NUMBER - 1, 1);
	
	cout << "0부터 11번째 데이터까지의 구간 합 : " << sum(0, NUMBER - 1, 1, 0, 11) << "\n";

	update(0, NUMBER - 1, 1, 5, -3);

	cout << "0부터 11번째 데이터까지의 구간 합 : " << sum(0, NUMBER - 1, 1, 0, 11) << "\n";

	cout << "0부터 3번째 데이터까지의 구간 합 : " << sum(0, NUMBER - 1, 1, 0, 3) << "\n";

	return 0;
}