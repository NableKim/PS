/*

N���߿� C���� �����Ͽ� �����⸦ ��ġ�ϵ� ���� ������ �� �������� ���� �Ÿ��� �ִ��� ũ���϶�

�����Ⱓ �Ÿ��� ������ 1 ~ (�糡���� �Ÿ�)
�Ÿ� ������ �߰����� ã��
�� ���ݴ�� �����⸦ ��ġ�Ѵٸ� � ��ġ�� �� �ִ°�?
C�� �̻� ��ġ�� �� �ִ°�?
	answer�� ����
	left = mid+1
���ϸ�
	right = mid-1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int N, C;
	cin >> N >> C;

	for (int i = 0, tmp; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int left = 1;
	int right = v[v.size() - 1] - v[0];
	int answer = 0;

	while (left <= right) {

		int mid = (left + right) >> 1;

		int preIdx = 0;
		int cnt = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] - v[preIdx] >= mid) {
				preIdx = i;
				cnt++;
			}
		}

		if (cnt >= C) {
			left = mid + 1;
			answer = answer < mid ? mid : answer;
		}
		else
			right = mid - 1;

	}

	cout << answer;

	return 0;
}