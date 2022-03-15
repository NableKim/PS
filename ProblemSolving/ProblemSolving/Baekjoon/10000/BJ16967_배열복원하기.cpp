#include <cstdio>
using namespace std;

#define MAX_LENGTH1 300
#define MAX_LENGTH2 MAX_LENGTH1*2

int A[MAX_LENGTH1][MAX_LENGTH1];
int B[MAX_LENGTH2][MAX_LENGTH2];

int main() {

	int H, W, X, Y;
	scanf(" %d %d %d %d", &H, &W, &X, &Y);

	for (int y = 0; y < H+X; y++) {
		for (int x = 0; x < W+Y; x++) {
			scanf(" %d", &B[y][x]);
		}
	}

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (y >= X && x >= Y)
				A[y][x] = B[y][x] - A[y - X][x - Y];
			else
				A[y][x] = B[y][x];
		}
	}

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++)
			printf("%d ", A[y][x]);
		printf("\n");
	}

	return 0;
}