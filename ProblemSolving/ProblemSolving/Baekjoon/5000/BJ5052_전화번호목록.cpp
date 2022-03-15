#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a.size() < b.size();
}

unordered_map<string, bool> um;
string v[10000];

bool isConsistency(string str) {
	for (int j = 1; j < str.size(); j++) { // 100
		string s = str.substr(0, j);
		if (um[s]) return false;
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
		
		sort(v, v + n, cmp); // nlogn

		for (string& s : v)
			um[s] = true;

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