#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int Y, X;
	scanf("%d %d", &Y, &X);
	
	int input;
	int map[1001];
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			scanf(" %d", &input);
			
			if (y == 1)
				map[x] = map[x - 1] + input;
			else
				map[x] = max(map[x],map[x - 1])+input;
		}
	}

	printf("%d", map[X]);

	return 0;
}