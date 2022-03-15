#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<long long, bool> um;
long long v[10000];

int getLength(long long ll) {
	int cnt = 1;
	while (ll >= 10) {
		ll /= 10;
		cnt++;
	}
	return cnt;
}

long long pow(int n) {
	if (n == 0) return 1;
	return 10 * pow(n - 1);
}

long long getSubNumber(long long ll, int len, int sub_len) {
	return ll/pow(len - sub_len);
}

bool isConsistency(long long ll) {
	int len = getLength(ll);	// 10
	for (int j = 1; j < len; j++) { // 10
		long long sub_ll = getSubNumber(ll, len, j); // 10
		if (um[sub_ll]) return false;
	}
	return true;
}

void init() {
	um.clear();
}

int main() {

	freopen("Text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {

		init();

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)	// n
			cin >> v[i];

		sort(v, v + n); // nlogn

		for (long long& ll : v)
			um[ll] = true;

		bool flag = true;
		for (int i = 0; i < n; i++) { // n
			if (!isConsistency(v[i])) { // 100
				flag = false;
				break;
			}
		}

		if (flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}