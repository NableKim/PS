// 이분탐색 문제임을 사전에 알고 시작을 했으나 어떻게 사용해야하는지 감을 못잡음
// 주어진 정보에서만 이분탐색을 할 수 있는게 아니고...
// 주어진 정보에서 파생된 정보를 만들고 이를 바탕으로 이분탐색하는 것도 생각할 수 있어야함.
// 원하는건 n명의 사람이 입국심사를 받는데까지 걸리는 최소 시간임
// 연속된 시간의 최소, 최대 범위를 정하고 이분탐색을 진행한다.
// mid 시간까지 몇명을 심사할 수 있는가?
	// n보다 적은 인원을 심사하였다면 시간이 더 필요한거고
	// n보다 많은 인원을 심사하였다면 시간이 더 줄어도 되는거고
	// n명의 인원을 심사하였다면, 이 시간이 정답이거나 아주 살짝 더 줄여도 될거같고
	// >> 이 사항을 종합해보면 n보다 적은 인원을 심사하였는가, 아닌가에 따라 구분할 수 있음.

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	unsigned long long answer = 0;

	unsigned long long left = 1;
	unsigned long long right = ULLONG_MAX-1;
	int tSize = times.size();

	while (left <= right) {
		unsigned long long mid = (left + right) / 2;

		// mid 시간까지 최대 몇명을 심사할 수 있는가
		unsigned long long cnt = 0;
		for (int i = 0; i < tSize; i++)
			cnt += mid / (times[i]);

		if (cnt >= n) {
			answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << answer;

	return answer;
}

int main() {
	
	solution((long long)6, { 7, 10 });

	return 0;
}