#include <cstdio>
#include <cstring>
using namespace std;

int A[200];
int F[201];

int main() {

	int N;
	scanf("%d", &N);

	A[0] = 1;
	for (int n = N; n > 1; n--) {
		memset(F, 0, sizeof(F));
		for (int idx = 0; idx < 200; idx++) {
			int tmp = A[idx] * n;
			tmp += F[idx];
			if (tmp >= 10) {
				int r = tmp % 10;
				A[idx] = r;
				F[idx + 1] += (tmp / 10);
			}
			else {
				A[idx] = tmp;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 200; i++)
		sum += A[i];
	
	printf("%d", sum);
}