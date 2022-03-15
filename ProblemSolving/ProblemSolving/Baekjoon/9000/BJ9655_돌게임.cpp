/*
N이 홀수냐 짝수냐에 따라 이미 결과는 정해져있음
*/

#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int N;
	cin >> N;

	if (N & 1)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}