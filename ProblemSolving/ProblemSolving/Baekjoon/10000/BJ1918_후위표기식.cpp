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

	// ���� ǥ����� ���� ǥ������� ���� �� ���� ������ �״�� ����

	// ���ÿ��� �ռ� ���� ��ȣ�� �����ڸ� �����ϴµ�
	// ���� �����ں��� �켱������ ���� �����ڰ� �ִٸ� �װ͵� ���� ���������ϴϱ� ������ְ� ���ÿ� ����
	// ���� (��ȣ�� ���Դٸ� �ϴ� ���ÿ� �ֱ�
	// )��ȣ�� ���Դٸ� (��ȣ�� ���ö����� ���� pop���ֱ�
	// ���̻� �߰��� �����ڰ� ���µ� ������ ��� �ִٸ� ���� ���

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