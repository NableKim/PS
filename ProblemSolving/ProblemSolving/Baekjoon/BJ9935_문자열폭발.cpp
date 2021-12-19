#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string str;
	cin >> str;

	string pattern;
	cin >> pattern;

	char end = pattern[pattern.size() - 1];

	string s = "";
	for (int i = 0; i < str.size(); i++) {
		
		if (str[i] == end && s.size() >= pattern.size() - 1) {
			string tmp = "";
			for (int j = pattern.size() - 1; j > 0; j--) {
				tmp += s[s.size()-j];
			}
			tmp += str[i];

			if (tmp == pattern) {
				for (int j = pattern.size() - 1; j > 0; j--) {
					s.pop_back();
				}
				continue;
			}
		}
		s += str[i];
	}

	if (s.size() == 0)
		s = "FRULA";

	cout << s;

	return 0;
}