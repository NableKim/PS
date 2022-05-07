#include <iostream>

// MBTI ���� ���� ��ǥ �˻� ����

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

	// 1�� ��ǥ
	if (um['R'] < um['T'])
		answer[0] = 'T';

	// 1�� ��ǥ
	if (um['C'] < um['F'])
		answer[1] = 'F';

	// 1�� ��ǥ
	if (um['J'] < um['M'])
		answer[2] = 'M';

	// 1�� ��ǥ
	if (um['A'] < um['N'])
		answer[3] = 'N';

	return answer;
}

string solution(vector<string> survey, vector<int> choices) {

	init();

	// �� �������� ������ �亯�� ����
		// �� ���ں� ������ ī����

	for (int i = 0; i < choices.size(); i++) {

		if (choices[i] == 4) continue;
		else if (choices[i] < 4) {
			// ~��
			char ch = survey[i][0];
			um[ch] += 4 - choices[i];
		}
		else {
			// ~��
			char ch = survey[i][1];
			um[ch] += choices[i] - 4;
		}

	}

	// �������� �� ��ǥ�� �켼�� �� �����ؼ� �־��ֱ�
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
