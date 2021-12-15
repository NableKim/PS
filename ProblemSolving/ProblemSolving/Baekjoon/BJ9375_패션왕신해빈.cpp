#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> um;
vector<int> arr;
vector<int> pick;
int answer;

string splitWithSpace(string str) {
	int idx = 0;
	while (str[idx] != ' ')
		idx++;
	return str.substr(idx + 1);
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		// 의상별 몇개를 소유하는지 확인
		string input;
		getline(cin, input);
		for (int i = 0; i < N; i++) {
			getline(cin, input);
			string kind = splitWithSpace(input);
			um[kind]++;
		}

		unordered_map<string, int>::iterator it;
		for (it = um.begin(); it != um.end(); it++) {
			arr.push_back(it->second);
		}

		// 의상을 입는 경우의 수 구하기
		int answer = 1;
		for (int i = 0; i < arr.size(); i++) {
			answer *= (arr[i] + 1);
		}

		// 정답 출력
		cout << answer-1 << "\n";

		um.clear();
		arr.clear();
	}

	return 0;
}