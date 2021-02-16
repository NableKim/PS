#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> d, int budget);

int main() {;
	
	int budget = 9;
	vector<int> d = {1, 3, 2, 5, 4};
	
	printf("%d", solution(d, budget));

	return 0;
}

int solution(vector<int> d, int budget) {
	int answer = 0;
	sort(d.begin(), d.end());
	
	int sum = 0;
	for (int &cost : d)
	{
		if (sum + cost <= budget) {
			sum += cost;
			answer++;
		}
	}
	return answer;
}