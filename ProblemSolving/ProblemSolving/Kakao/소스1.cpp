#include <iostream>

// MBTI 같은 성격 지표 검사 문제

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> um;

void init() {
	um['R'] = 0;
	um['T'] = 0;
	um['C'] = 0;
	um['F'] = 0;
	um['J'] = 0;
	um['M'] = 0;
	um['A'] = 0;
	um['N'] = 0;
}

string setAnswer() {

	string answer = "RCJA";

	// 1번 지표
	if (um['R'] < um['T'])
		answer[0] = 'T';

	// 1번 지표
	if (um['C'] < um['F'])
		answer[1] = 'F';

	// 1번 지표
	if (um['J'] < um['M'])
		answer[2] = 'M';

	// 1번 지표
	if (um['A'] < um['N'])
		answer[3] = 'N';

	return answer;
}

string solution(vector<string> survey, vector<int> choices) {

	init();

	// 각 문제에서 선택한 답변을 보고
		// 각 문자별 점수를 카운팅

	for (int i = 0; i < choices.size(); i++) {

		if (choices[i] == 4) continue;
		else if (choices[i] < 4) {
			// ~형
			char ch = survey[i][0];
			um[ch] += 4 - choices[i];
		}
		else {
			// ~형
			char ch = survey[i][1];
			um[ch] += choices[i] - 4;
		}

	}

	// 마지막에 각 지표별 우세한 걸 생각해서 넣어주기
	string answer = setAnswer();

	return answer;
}

int main() {

	vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
	vector<int> choices = { 5, 3, 2, 7, 5 };

	string answer = solution(survey, choices);
	cout << answer;
	/*vector<int> answers = solution();
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;*/

	return 0;
}
