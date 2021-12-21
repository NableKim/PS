#include <cstdio>
#include <string>
using namespace std;

int N;
string str = "12";

void dfs(int depth) {
	if (depth == N) {
		return;
	}

	bool check[4] = { false, };

	// 바로 직전의 원소
	int left = 0, right;
	for (int len = depth/2; len >=1; len--) {
		right = left + len;
		bool flag = true;
		for (int i = 0; i < len-1; i++) {
			if (str[left + i] != str[right + i]) {
				flag = false;
				break;
			}
		}
		if (flag)
			check[str[left + len - 1] - '0'] = true;
		left = right;
	}

	for (int i = 1; i <= 3; i++) {
		if (!check[i]) {
			str += to_string(i);
			dfs(depth + 1);
			break;
		}
	}
}


int main() {

	scanf("%d", &N);

	if (N < 2)
		str.pop_back();
	else
		dfs(2);

	printf("%s", str.c_str());

	return 0;
}