/*
26���� ���ĺ� �ҹ����� �������θ� ������ �迭�� ����
ó�� ���ں��� �� ���ڱ��� �Ʒ� ������ �ݺ�
	���� ����Ű�� ���ڰ� ���� ���ڿ� �ٸ��ٸ�
		���� ���ڰ� ������ ������ ���� ������ Ȯ��
			������ �׷�ܾ� �ƴϹǷ� ����
		���� ���ڸ� ���� ���ڷ� ������Ʈ
*/

#include <iostream>
#include <string>
using namespace std;


int main() {

	//freopen("Text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++) {
		bool check[26] = { false, };

		string str;
		cin >> str;

		int j;
		char pre = 'A';
		for (j = 0; j < str.size(); j++) {
			if (str[j] != pre) {
				pre = str[j];
				if (check[pre - 'a']) 	
					break;
				check[pre - 'a'] = true;
			}
		}

		if (j == str.size())
			answer++;
	}

	cout << answer;


	return 0;
}