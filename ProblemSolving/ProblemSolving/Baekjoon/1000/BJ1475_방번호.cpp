#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	cin >> str;

	int C[10] = { 0, };

	for (int i = 0; i < str.length(); i++)
		C[str[i] - '0']++;

	int sum = C[6] + C[9];
	if (sum % 2 == 1)
		sum++;

	C[6] = C[9] = sum / 2;

	int maxVal = 0;
	for (int i = 0; i < 10; i++) {
		if (maxVal < C[i])
			maxVal = C[i];
	}
	
	cout << maxVal;

	return 0;
}