#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<long long> len_v;

string dfs(long long k, long long n) {

	if (k == 0) {
		if (n == 1)
			return "m";
		return "o";
	}

	long long term = len_v[k - 1];	// Sk-1의 길이

	if (n > 0 && n <= term) {
		return dfs(k - 1, n);
	}
	else if (n >= term + 1 && n <= term + k + 3) {
		if (n == term + 1)
			return "m";
		return "o";
	}
	else {
		return dfs(k - 1, n-(term+k+3));
	}
}

long long lower_bound(int left, int right, int target) {

	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (len_v[mid] >= target)
			right = mid - 1;
		else
			left = mid +1;
	}
	return right + 1;
}

int main() {

	long long N;
	scanf(" %lld", &N);

	// K에 따른 Sk 문자열의 길이를 구함
	len_v.push_back(3);
	long long k = 1;
	while (1) {
		len_v.push_back(len_v[k - 1] * 2 + (k + 3));
		k++;
		if (len_v[k - 1] >= N)
			break;
	}

	k = lower_bound(0, k, N);

	string answer = dfs(k, N);

	printf("%s", answer.c_str());

	return 0;
}