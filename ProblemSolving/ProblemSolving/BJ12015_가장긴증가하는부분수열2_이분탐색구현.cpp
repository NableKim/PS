#include <iostream>
using namespace std;

#define MAX_N 1000001
#define INF 99999999

int N;
int A[MAX_N];
int C[MAX_N];

int _lower_bound(int startIndex, int arrSize, int target) {
	
	int left = startIndex;
	int right = arrSize;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (C[mid] >= target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right+1;
}

int main() {

	//freopen("Text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	setbuf(stdout, NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		C[i] = INF;
	}

	int maxIndex = -1;
	for (int i = 0; i < N; i++) {
		if (maxIndex == -1 
			|| (maxIndex>-1 && C[maxIndex] < A[i]))
			C[++maxIndex] = A[i];
		else {
			int index = _lower_bound(0, N, A[i]);
			C[index] = A[i];
		}
	}

	cout << maxIndex+1;

	return 0;
}
