/*
*** deque ������ ����ؼ� ���ϴ� ���ڸ� ������ ã��

�̾Ƴ����� ���� ������� �Ʒ� ������ �ݺ��Ѵ�
	Ÿ���� �Ǵ� ���ڸ� �̱� ���� ���ʿ��� ���� �������� �����ʿ��� ���� �������� ���
	Ÿ���� �Ǵ� ���ڸ� ���� ������ ������ ���� �������� queue front/back Ȯ���Ѵ�
	queue pop ����
		front�� ���� ��Ȳ�̶��
			front�� ã�� �����
				������
			�ƴ϶��
				back�� ����
				���갳��++
		back�� ���� ��Ȳ�̶��
			front�� ����
			���갳��++
			back�� ã�� �����ٸ�
				front ������
				������
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
		int dir = 0;	// 0�� front���� pop, 1�� back���� pop

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