#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAP_SIZE 101

int map[MAP_SIZE][MAP_SIZE];

struct P {
	int y, x;
};

int simul(int y1, int x1, int y2, int x2) {

	queue<int> v;
	queue<P> pv;

	int min = 99999999;
	for (int y = y1; y <= y2; y++) {
		pv.push({ y, x1 });
		v.push(map[y][x1]);
		min = min > map[y][x1] ? map[y][x1] : min;
		map[y][x1] = 0;
	}

	for (int x = x1+1; x <= x2; x++) {
		pv.push({ y2, x });
		v.push(map[y2][x]);
		min = min > map[y2][x] ? map[y2][x] : min;
		map[y2][x] = 0;
	}

	for (int y = y2-1; y >= y1; y--) {
		pv.push({ y, x2 });
		v.push(map[y][x2]);
		min = min > map[y][x2] ? map[y][x2] : min;
		map[y][x2] = 0;
	}

	for (int x = x2 - 1; x >= x1+1; x--) {
		pv.push({ y1, x });
		v.push(map[y1][x]);
		min = min > map[y1][x] ? map[y1][x] : min;
		map[y1][x] = 0;
	}

	v.push(v.front()); v.pop();
	
	while (!pv.empty()) {
		P front = pv.front(); pv.pop();
		map[front.y][front.x] = v.front();
		v.pop();
	}

	return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	for (int y = 1; y <= rows; y++) {
		for (int x = 1; x <= columns; x++)
			map[y][x] = columns * (y - 1) + x;
	}

	for (vector<int> &q : queries) {
		int y1 = q[0];
		int x1 = q[1];
		int y2 = q[2];
		int x2 = q[3];

		answer.push_back(simul(y1, x1, y2, x2));
	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v = solution(6, 6, { {2,2,5,4 }, {3,3,6,6}, {5,1,6,3} });

	for (int& ve : v)
		cout << ve << " ";

	//freopen("Text.txt", "r", stdin);


	return 0;
}