#include <cstdio>
using namespace std;

void swap(int* A, int* B) {
	int tmp = *A;
	*A = *B;
	*B = tmp;
}

int GCD(int A, int B) {
	if (A < B) swap(&A, &B);
	while (B != 0) {
		int tmp = A;
		A = B;
		B = tmp % B;
	}
	return A;
}

int LCM(int A, int B) {
	return (A * B) / GCD(A, B);
}


int main() {
	
	int N;
	scanf("%d", &N);

	int A = 1;
	for (int B = 2; B <= N; B++) {
		A = LCM(A, B);
	}
	printf("%d", A);

	return 0;
}