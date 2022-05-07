#include <iostream>

#include <string>
#include <vector>
using namespace std;

#define INF 987654321

int solution(vector<int> queue1, vector<int> queue2) {

	int qSize = queue1.size();
	long long totalSum = 0, halfSum = 0;
	vector<int> totalList = queue1;

	long long sum1 = 0;
	for (int i = 0; i < qSize; i++) {
		totalList.push_back(queue2[i]);
		totalSum += ((long long)queue1[i] + (long long)queue2[i]);
		sum1 += (long long)queue1[i];
	}
	halfSum = totalSum / 2;

	if (totalSum % 2 == 1)
		return -1;

	if (sum1 == halfSum)
		return 0;
	

	int left = 0, right = 0;
	long long rangeSum = totalList[0];
	int minCnt = INF;

	while (left <= right && right < 2*qSize) {
		if (rangeSum < halfSum) {
			right++;
			if (right < 2 * qSize)
				rangeSum += totalList[right];
		}
		else if (rangeSum > halfSum) {
			rangeSum -= totalList[left];
			left++;
		}
		else {
			
			int cnt = 0;
			if (right < qSize) {
				cnt += left;
				cnt += (qSize + cnt);
				cnt += (right - left + 1);
			}
			else if (left < qSize && qSize <= right) {
				cnt += left;
				cnt += (right - qSize + 1);
			}
			else {
				cnt += left - qSize;
				cnt += left;
				cnt += (right - left + 1);
			}

			if (minCnt > cnt)
				minCnt = cnt;

			right++;
			if(right < 2 * qSize)
				rangeSum += totalList[right];
		}
	}

	if (minCnt == INF)
		minCnt = -1;

	return minCnt;
}

int main() {

	//vector<int> queue1 = { 3, 2, 7, 2 };
	//vector<int> queue2 = { 4, 6, 5, 1 };
	//vector<int> queue1 = { 1, 1, 1, 1 };
	//vector<int> queue2 = { 1, 3, 3, 1 };

	//vector<int> queue1 = { 3, 1 };
	//vector<int> queue2 = { 1, 1 };

	vector<int> queue1 = { 1, 1, 1, 1 };
	vector<int> queue2 = { 1, 1, 2, 1 };
	

	int answer = solution(queue1, queue2);
	cout << answer;
	/*vector<int> answers = solution();
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;*/

	return 0;
}


// 같은 경우를 만났으면 메모

			// left을 제외한 왼쪽에 있는 것들을 오른쪽 큐로 옮겨주기
			// 오른쪽 큐에 있는 것들을 왼쪽 큐로 옮겨주기
			// left~right에 있는 것들을 오른쪽 큐로 옮겨주기

			// left를 제외한 왼쪽에 있는 것들 오른쪽으로 옮기기
			// mid값~right까지 데이터 왼쪽 큐로 옮기기

			// mid~left(제외)에 있는 것들 왼쪽 큐에 옮기기
			// 왼쪽 큐에 있는 것들 오른쪽 큐로 옮기기
			// left~right를 왼쪽 큐로 옮기기