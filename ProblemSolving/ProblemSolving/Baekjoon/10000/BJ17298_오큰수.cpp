#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	vector<int> v;
	for (int i = 0, input; i < N; i++) {
		scanf(" %d", &input);
		v.push_back(input);
	}

	vector<int> ans;
	stack<int> st;
	for (int i = N - 1; i >= 0; i--) {

		while (!st.empty() && st.top() <= v[i]) st.pop();

		if (st.empty())
			ans.push_back(-1);
		else
			ans.push_back(st.top());

		st.push(v[i]);
	}

	for (int i = N - 1; i >= 0; i--)
		printf("%d ", ans[i]);

	return 0;
}