#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> v;
vector<int> v2;
unordered_map<int, bool> um;

int lb(int left, int right, int target) {

	while (left <= right) {

		int mid = (left + right) >> 1;

		if (target <= v[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right + 1;
}


int main() {

	int N;
	scanf(" %d", &N);

	for (int i = 0, input; i < N; i++) {
		scanf(" %d", &input);
	
		v2.push_back(input);

		if (!um[input]) {
			v.push_back(input);
			um[input] = true;
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		printf("%d ", lb(0, v.size()-1, v2[i]));

 	return 0;
}