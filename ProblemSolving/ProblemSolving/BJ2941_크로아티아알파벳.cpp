#include <iostream>
#include <string>
using namespace std;

int main() {

	setbuf(stdout, NULL);

	string input;
	cin >> input;

	int index = 0;
	
	int answer = 0;
	int len = input.length();
	while (index < len) {

		if (index == len - 1) {
			answer++;
			break;
		}

		string tmp = "";
		switch (input[index])
		{
		case 'c' :
			if (input[index + 1] == '=' || input[index + 1] == '-')
				index++;
			break;
		case 'd':
			if (len - index >= 3
				&& input[index + 1] == 'z'
				&& input[index + 2] == '=')
				index += 2;
			else if (input[index + 1] == '-')
				index++;
			break;
		case 'l':
		case 'n':
			if (input[index + 1] == 'j')
				index++;
			break;
		case 's':
		case 'z':
			if (input[index + 1] == '=')
				index++;
			break;
		default:
			break;
		}

		index++;
		answer++;
	}

	cout << answer;

	return 0;
}