/*
선형탐색으로 구하는게 가장 간단하나 다른 방법을 생각해봄
세그멘트 트리로 구간합을 출력한다
*/

#include <iostream>
using namespace std;

int ST[2048];

int rangeSum(int L, int R, int l, int r) {

	if (l > r)
		return 0;

	if (l == r)
		return ST[l];

	if (L <= l && r <= R) {
		int mid = (L + R) / 2;
		if (r <= mid)
			return rangeSum(L, mid, l, r);
		else if (l > mid)
			return rangeSum(mid + 1, R, l, r);
		else
			return rangeSum(L, mid, l, mid) + rangeSum(mid, R, mid + 1, r);
	}
	else if (l < L && r <= R) {
		return rangeSum(L, R, L, r);
	}
	else if (L <= l && R < r) {
		return rangeSum(L, R, l, R);
	}
	else
		return ST[(L + R) / 2];
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int l, r;
	cin >> l >> r;

	int val = 1;
	int cnt = 0;
	for (int i = 1024; i < 2048; i++) {
		ST[i] = val;
		cnt++;
		if (val == cnt) {
			val++;
			cnt = 0;
		}
	}

	for (int i = 1023; i > 0; i--)
		ST[i] = ST[i * 2] + ST[i * 2 + 1];

	cout << rangeSum(1024, 2047, l+1023, r+1023);
	
	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int l, r;
	cin >> l >> r;

	int val = 1;
	int cnt = 0;
	for (int i = 1024; i < 2048; i++) {
		ST[i] = val;
		cnt++;
		if (val == cnt) {
			val++;
			cnt = 0;
		}
	}

	for (int i = 1023; i > 0; i--)
		ST[i] = ST[i * 2] + ST[i * 2 + 1];

	cout << rangeSum(1024, 2047, l + 1023, r + 1023);

	return 0;
}