#include <iostream>
using namespace std;

#define MAP_LENGTH 101

bool map[MAP_LENGTH][MAP_LENGTH];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("Text.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int X, Y;
		cin >> X >> Y;

		for (int x = X; x < X + 10; x++) {
			for (int y = Y; y < Y + 10; y++)
				map[y][x] = true;
		}
	}

	int cnt = 0;
	for (int x = 1; x < MAP_LENGTH; x++) {
		for (int y = 1; y < MAP_LENGTH; y++)
			if (map[y][x]) cnt++;
	}

	cout << cnt;

	return 0;
}