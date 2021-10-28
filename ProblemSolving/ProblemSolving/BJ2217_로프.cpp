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