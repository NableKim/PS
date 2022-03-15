#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 1000001

int N;
int A[MAX_N];
int C[MAX_N];

int main() {

	//freopen("Text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	setbuf(stdout, NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		C[i] = MAX_N;
	}

	vector<int> vt;
	for (int i = 0; i < N; i++) {
		if (vt.empty() || vt.back() < A[i])
			vt.push_back(A[i]);
		else {
			auto it = lower_bound(vt.begin(), vt.end(), A[i]);
			*it = A[i];
		}
	}

	cout << vt.size();

	return 0;
}
