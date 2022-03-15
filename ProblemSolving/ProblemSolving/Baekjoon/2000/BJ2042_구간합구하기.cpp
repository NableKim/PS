#include <cstdio>
using namespace std;

#define TWO_10 1024
#define TWO_20 TWO_10 * TWO_10
#define TWO_21 TWO_20 * 2

long long segment_tree[TWO_21];

void changeNodeValue(int node, long long diff) {
	if (node < 1) return;
	segment_tree[node] += diff;
	changeNodeValue(node / 2, diff);
}

long long getPartialSum(int node, int cv_left, int cv_right, int qu_left, int qu_right) {

	// 범위를 벗어난 경우
	if (qu_right < cv_left || cv_right < qu_left)
		return 0;

	// 원하는 구간의 합을 구한 경우
	if (cv_left == qu_left && cv_right == qu_right)
		return segment_tree[node];

	int mid = (cv_left + cv_right) / 2;

	if (qu_right <= mid) {
		return getPartialSum(node * 2, cv_left, mid, qu_left, qu_right);
	}
	else if (qu_left > mid) {
		return getPartialSum(node * 2+1, mid+1, cv_right, qu_left, qu_right);
	}
	else {
		return getPartialSum(node * 2, cv_left, mid, qu_left, mid) 
			+ getPartialSum(node * 2 + 1, mid + 1, cv_right, mid+1, qu_right);
	}
}

long long makeSegmentTree(int node) {
	if (node >= TWO_20)
		return segment_tree[node];
	return segment_tree[node] = makeSegmentTree(node * 2) + makeSegmentTree(node * 2 + 1);
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
		scanf(" %lld", &segment_tree[TWO_20 + i]);

	// 세그멘트 트리 만들기
	makeSegmentTree(1);

	int a, b;
	long long c;
	for (int i = 0; i < M + K; i++) {
		scanf(" %d %d %lld", &a, &b, &c);
		if (a == 1) {
			long long diff = c - segment_tree[TWO_20 + b - 1];
			changeNodeValue(TWO_20 + b - 1, diff);
		}
		else {
			printf("%lld\n", getPartialSum(1, TWO_20, TWO_21 - 1, TWO_20 + b-1, TWO_20 +c-1));
		}
	}

	return 0;
}