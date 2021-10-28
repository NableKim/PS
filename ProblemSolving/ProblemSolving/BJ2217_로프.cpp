/*
*** 로프를 병렬로 연결하되 최대한 내구도가 높은 로프들로 묶는게 중요

로프별 내구도 값을 기준으로 오름차순 정렬
모든 밧줄을 병렬로 연결했다고 생각
내구도 값이 가장 낮은 로프를 하나씩 제외하며 들 수 있는 무게 계산
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 100001

int arr[N_MAX];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int sum = arr[i] * (N - i);
		answer = answer < sum ? sum : answer;
	}

	cout << answer;

	return 0;
}