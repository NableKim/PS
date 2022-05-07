#include <iostream>

// 길이가 같은 두 큐가 주어지고
// 양쪽의 큐의 원소 합이 동일해질때까지 최소 몇번 연산해야하는가
// 연산은 두 큐 중에서 한쪽 큐를 골라 front를 다른쪽 queue 맨 뒤에 넣는게 한번의 연산임

#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int idx1;
	long long sum1;
	int idx2;
	long long sum2;
	int cnt;
};

queue<Info> q;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = 0;

	// 벡터 연장
	int qSize = queue1.size();
	long long sum1, sum2;
	sum1 = sum2 = 0;
	for (int i = 0; i < qSize; i++) {
		queue1.push_back(queue2[i]);
		queue2.push_back(queue1[i]);
		sum1 += queue1[i];
		sum2 += queue2[i];
	}
	
	// bfs 탐색 시키기
	q.push({ 0, sum1, 0, sum2, 0 });

	while (!q.empty()) {

		Info front = q.front();
		q.pop();

		if (front.sum1 == front.sum2) {
			answer = front.cnt;
			break;
		}

		if (front.cnt >= qSize * 2) {
			answer = -1;
			break;
		}

		// 1 -> 2로 가는 경우
		q.push({ front.idx1 + 1, 
			front.sum1 - queue1[front.idx1], 
			front.idx2, 
			front.sum2 + queue1[front.idx1], 
			front.cnt+1});
		
		// 2 -> 1로 가는 경우
		q.push({ front.idx1, 
			front.sum1 + queue2[front.idx2], 
			front.idx2+1, 
			front.sum2 - queue2[front.idx2], 
			front.cnt + 1});

	}

	return answer;
}

int main() {

	vector<int> queue1 = { 3, 2, 7, 2 };
	vector<int> queue2 = { 4, 6, 5, 1 };

	int answer = solution(queue1, queue2);
	cout << answer;
	/*vector<int> answers = solution();
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;*/

	return 0;
}
