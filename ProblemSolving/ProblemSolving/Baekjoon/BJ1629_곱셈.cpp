#include <cstdio>
using namespace std;

int pow(long long a, long long b, long long c) {
	if (b == 0)
		return 1;

	long long half = pow(a, b/2, c) % c;
	if (b % 2)
		return (((half*half)%c) * a)%c;
	return (half*half) % c;
}

int main() {

	long long A, B, C;
	scanf(" %lld %lld %lld", &A, &B, &C);

	A %= C;

	printf("%d", pow(A, B, C));
	
	return 0;
}