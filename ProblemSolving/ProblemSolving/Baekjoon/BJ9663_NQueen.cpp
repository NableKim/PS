#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct POINT {
	int y, x;
};

vector<POINT> preQueen;
bool check[15];
int answer;
int N;

void func(int row) {
	if (row == N) {
		answer++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (check[col]) continue;
		
		bool possible = true;
		for (int i = 0; i < preQueen.size(); i++) {

			if (row - preQueen[i].y == abs(col - preQueen[i].x)) {
				possible = false;
				break;
			}
		}

		if (!possible) continue;
		
		check[col] = true;
		preQueen.push_back({ row, col });
		func(row + 1);
		check[col] = false;
		preQueen.pop_back();
	}
}

int main() {

	scanf(" %d", &N);

	func(0);

	printf("%d", answer);

	return 0;
}