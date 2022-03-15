#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, bool> um;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		um[name] = true;
	}

	vector<string> ans;
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (um[name])
			ans.push_back(name);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (string& s : ans)
		cout << s << "\n";

	return 0;
}