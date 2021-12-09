#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUM 1121

bool isntPrime[MAX_NUM];

int main() {

	int N = 1120;

	vector<int> v;
	for (int i = 2; i * i <= N; i++) {
		for (int j = 2; j * i <= N; j++) {
			isntPrime[i * j] = true;
			
		}
	}

	for(int i=2; i<MAX_NUM; i++)
		if(isntPrime[i])
			v.push_back(i);

	return 0;
}