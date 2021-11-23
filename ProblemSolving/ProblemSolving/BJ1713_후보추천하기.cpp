/*
�ĺ��� ��ϵ� ���� N�� �ɶ������� �ĺ� ���.
�ĺ����� �̹� N�� ���¶� ��ü�� �ʿ��� ���, ������ ���ؼ� ��ü ����� ã�� ������Ʈ
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P {
	int idx;
	int num;
	int cnt;
};

int N, M;
vector<P> pick;
bool exist[1001];

bool cmp(P a, P b) {
	if (a.cnt == b.cnt)
		return a.idx < b.idx;
	return a.cnt < b.cnt;
}

int main() {

	//freopen("Text.txt", "r", stdin);

	scanf(" %d %d", &N, &M);

	for (int i = 0, num; i < M; i++) {

		scanf(" %d", &num);
	
		if (exist[num]) {
			for (int j = 0; j < pick.size(); j++) {
				if (pick[j].num == num) {
					pick[j].cnt++;
					break;
				}
			}
		}
		else {
			if (pick.size() == N) {
				sort(pick.begin(), pick.end(), cmp);
				exist[pick[0].num] = false;
				pick[0] = { i, num, 1 };
			}
			else {
				pick.push_back({ i, num, 1 });
			}
			exist[num] = true;
		}
	}

	vector<int> answer;

	for (int i = 0; i < pick.size(); i++)
		answer.push_back(pick[i].num);

	sort(answer.begin(), answer.end());

	for (int i = 0; i < pick.size(); i++)
		printf("%d ", answer[i]);

	return 0;
}