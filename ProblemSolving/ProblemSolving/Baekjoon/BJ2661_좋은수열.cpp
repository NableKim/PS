#include <cstdio>
#include <string>
using namespace std;

int N;
string str = "";

void dfs(int depth) {
	if (depth == N) {
		return;
	}

	bool check[4] = { false, };
	if(str.size() >= 1)
		check[str[str.size() - 1] - '0'] = true;
	if(str.size() >= 2)
		check[str[str.size() - 2] - '0'] = true;

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

	dfs(0);

	printf("%s", str.c_str());

	return 0;
}