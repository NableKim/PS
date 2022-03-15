#include <iostream>
using namespace std;

int N;
string str;
int answer = 0x80000000;

void dfs(int left, bool opened, int index) {

	// 문자열 index의 범위를 벗어났다면
	if (index >= N) {
		answer = left > answer ? left : answer;
		return;
	}

	if (str[index] >= '0' || str[index] <= '9') {

		// 직전에 괄호가 열렸다면
		if (opened) {
			int a = 0;
			int b = str[index-2] - '0';
			int right = 0;

			switch (str[index - 1]) {
				case '+':
					a = str[index] - '0';
					right = b+a;
					break;
				case '-':
					a = str[index] - '0';
					right = b-a;
					break;
				case '*':
					a = str[index] - '0';
					right = b*a;
					break;
			}

			switch (str[index - 3]) {
				case '+':
					left += right;
					break;
				case '-':
					left -= right;
					break;
				case '*':
					left *= right;
					break;
			}

			dfs(left, false, index+2);
		}
		else {	// 직전에 괄호가 열리지않았다면

			// 이번에 괄호를 여는 경우
			if(index < N-1)
				dfs(left, true, index + 2);
			
			// 이번에 괄호를 닫는 경우
			int right = str[index] - '0';

			switch (str[index - 1]) {
				case '+':
					left += right;
					break;
				case '-':
					left -= right;
					break;
				case '*':
					left *= right;
					break;
			}
			dfs(left, false, index + 2);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//freopen("Text.txt", "r", stdin);

	cin >> N;

	cin >> str;

	// 문자열의 길이가 1이면
	if (N == 1)
		answer = str[0] - '0';
	else
		dfs(str[0] - '0', false, 2);

	cout << answer;

	return 0;
}