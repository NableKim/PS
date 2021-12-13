#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	//freopen("Text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string str;
		getline(cin, str);

		if (str == ".") break;

		int idx = 0;
		stack<int> st;

		while (str[idx] != '.') {
			if (str[idx] == '(' || str[idx] == '[')
				st.push(str[idx]);
			else if (str[idx] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					st.push(str[idx]);
					break;
				}
			}
			else if (str[idx] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					st.push(str[idx]);
					break;
				}
			}
			idx++;
		}
			
		if (st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}