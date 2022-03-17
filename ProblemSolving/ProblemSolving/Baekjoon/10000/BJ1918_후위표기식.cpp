#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	//freopen("Text.txt", "r", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	cin >> str;

	// 중위 표기식을 후위 표기식으로 만들 때 문자 순서는 그대로 나옴

	// 스택에는 앞서 나온 괄호와 연산자를 저장하는데
	// 현재 연산자보다 우선순위가 높은 연산자가 있다면 그것들 먼저 계산해줘야하니까 출력해주고 스택에 넣음
	// 만약 (괄호가 나왔다면 일단 스택에 넣기
	// )괄호가 나왔다면 (괄호가 나올때까지 스택 pop해주기
	// 더이상 추가할 연산자가 없는데 스택이 비어 있다면 정답 출력

	stack<char> st;
	for (char& ch : str) {
		if (ch >= 'A' && ch <= 'Z') {
			cout << ch;
			continue;
		}

		if (ch == '(')
			st.push(ch);
		else if (ch == '*' || ch == '/') {
			while (!st.empty() 
				&& st.top() != '('
				&& st.top() != '+' 
				&& st.top() != '-') {
				cout << st.top();
				st.pop();
			}
			st.push(ch);
		}
		else if (ch == '+' || ch == '-') {
			while (!st.empty()
				&& st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.push(ch);
		}
		else { // ')'
			while (!st.empty()
				&& st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}