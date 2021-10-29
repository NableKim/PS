/*

N개중에 C개를 선택하여 공유기를 설치하되 가장 인접한 두 공유기의 사이 거리가 최대한 크게하라

공유기간 거리의 범위는 1 ~ (양끝지점 거리)
거리 범위의 중간값을 찾고
그 간격대로 공유기를 설치한다면 몇개 설치할 수 있는가?
C개 이상 설치할 수 있는가?
	answer값 갱신
	left = mid+1
못하면
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