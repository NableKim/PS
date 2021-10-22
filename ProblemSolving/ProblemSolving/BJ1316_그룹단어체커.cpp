/*
26개의 알파벳 소문자의 출현여부를 저장할 배열을 선언
처음 문자부터 끝 문자까지 아래 과정을 반복
	지금 가리키는 문자가 이전 문자와 다르다면
		현재 문자가 이전에 출현된 적이 없는지 확인
			있으면 그룹단어 아니므로 종료
		이전 문자를 현재 문자로 업데이트
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