/*
N�� Ȧ���� ¦���Ŀ� ���� �̹� ����� ����������
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