/*
*** deque 구조를 사용해서 원하는 숫자를 빠르게 찾기

뽑아내야할 숫자 순서대로 아래 행위를 반복한다
	타겟이 되는 숫자를 뽑기 위해 왼쪽에서 부터 접근할지 오른쪽에서 부터 접근할지 계산
	타겟이 되는 숫자를 뽑을 때까지 위에서 정한 방향으로 queue front/back 확인한다
	queue pop 연산
		front를 보는 상황이라면
			front가 찾던 수라면
				끝내기
			아니라면
				back에 삽입
				연산개수++
		back을 보는 상황이라면
			front에 삽입
			연산개수++
			back이 찾던 수였다면
				front 꺼내기
				끝내기
*/

#include <cstdio>
#include <queue>
using namespace std;

deque<int> dq;

int main() {
	//freopen("Text.txt", "r", stdin);

	int N, M;
	scanf(" %d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	int answer = 0;
	for (int i = 0, num; i < M; i++) {
		scanf(" %d", &num);

		int left = 0;
		int right = dq.size() - 1;
		int dir = 0;	// 0은 front에서 pop, 1은 back에서 pop

		while (left != right) {

			if (dq.at(left++) == num) {
				dir = 0;
				break;
			}
			else if (dq.at(right--) == num) {
				dir = 1;
				break;
			}
		}

		if (dir == 0) {

			while (!dq.empty()) {
				int front = dq.front();
				dq.pop_front();

				if (num == front)
					break;

				dq.push_back(front);
				answer++;
			}
		}
		else {
			while (!dq.empty()) {
				int back = dq.back();
				dq.pop_back();

				dq.push_front(back);
				answer++;

				if (num == back) {
					dq.pop_front();
					break;
				}
			}
		}
	}

	printf("%d", answer);

	return 0;
}