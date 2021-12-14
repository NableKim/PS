#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, less<int>> left;
priority_queue<int, vector<int>, greater<int>> right;
vector<int> ans;

int main() {

	int N;
	scanf(" %d", &N);

	// 첫번째 입력
	int input;
	scanf(" %d", &input);
	
	int mid = input;
	ans.push_back(mid);

	for (int i = 1, input; i < N; i++) {
		scanf(" %d", &input);

		if (mid <= input)
			right.push(input);
		else
			left.push(input);

		int l_size = left.size();
		int r_size = right.size();

		if (r_size - l_size >= 2) {
			left.push(mid);
			mid = right.top();
			right.pop();
		}
		else if (l_size - r_size >= 1) {
			right.push(mid);
			mid = left.top();
			left.pop();
		}
		ans.push_back(mid);
	}

	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);

	return 0;
}