#include <cstdio>
#include <string>
using namespace std;

int N;
string str = "12";
string answer = "12";
bool found;
void dfs(int depth) {

	if (found) return;
	
	if (depth == N) {
		answer = str;
		found = true;
		return;
	}

	bool check[4] = { false, };

	// 바로 직전의 원소
	int right= depth;
	int left;

	for (int len = 1; len <= (depth+1) / 2; len++) {
		left = right - len;
		bool flag = true;
		for (int k = 0; k < len-1; k++) {
			if (str[left + k] != str[right + k]) {
				flag = false;
				break;
			}
		}
		if (flag)
			check[str[left + len - 1] - '0'] = true;
		right -= 1;
	}

	
	

	for (int i = 1; i <= 3; i++) {
		if (!check[i]) {
			str += to_string(i);
			dfs(depth + 1);
			str.pop_back();
		}
	}
}


int main() {

	scanf("%d", &N);

	if (N < 2)
		answer.pop_back();
	else
		dfs(2);

	printf("%s", answer.c_str());

	return 0;
}