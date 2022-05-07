#include <iostream>

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {

	int qSize = queue1.size();
	long long totalSum = 0, halfSum = 0;
	vector<int> totalList = queue1;
	
	for (int i = 0; i < qSize; i++) {
		totalList.push_back(queue2[i]);
		totalSum += ((long long)queue1[i] + (long long)queue2[i]);
	}
	halfSum = totalSum / 2;

	int left = 0, right = 0;
	int cnt = 0;	// 몇번 움직였는가
	long long rangeSum = totalList[0];

	while (left <= right) {
		if (rangeSum < halfSum) {
			right++;
			rangeSum += totalList[right];
			if (right >= qSize)
				cnt++;
		}
		else if(rangeSum > halfSum){
			rangeSum -= totalList[left];
			left++;
			cnt++;
		}
		else {
			/*if (right < qSize)
				cnt += left + qSize;*/
			break;
		}
	}

	if (left > right)
		cnt = -1;

	return cnt;
}

int main() {

	//vector<int> queue1 = { 3, 2, 7, 2 };
	//vector<int> queue2 = { 4, 6, 5, 1 };
	//vector<int> queue1 = { 1, 1, 1, 1 };
	//vector<int> queue2 = { 1, 3, 3, 1 };

	//vector<int> queue1 = { 3, 1 };
	//vector<int> queue2 = { 1, 1 };
	
	
	vector<int> queue1 = { 1, 3, 3, 1 };
	vector<int> queue2 = { 1, 1, 1, 1 };


	int answer = solution(queue1, queue2);
	cout << answer;
	/*vector<int> answers = solution();
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;*/

	return 0;
}
