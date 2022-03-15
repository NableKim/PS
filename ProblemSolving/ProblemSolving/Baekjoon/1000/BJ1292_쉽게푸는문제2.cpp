/*
선형탐색으로 구하는게 가장 간단
*/

#include <iostream>
using namespace std;

int map[1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int l, r;
	cin >> l >> r;

	int val = 1;
	int cnt = 0;
	for (int i = 1; i <= r; i++) {
		map[i] = val;
		cnt++;
		if (val == cnt) {
			val++;
			cnt = 0;
		}
	}

	int sum = 0;
	for (int i = l; i <= r; i++)
		sum += map[i];
	
	cout << sum;

	return 0;
}