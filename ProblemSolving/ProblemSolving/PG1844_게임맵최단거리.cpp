#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define LENGTH 100

int N, M;
int check[LENGTH][LENGTH];

struct P {
	int y, x;
};

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void bfs(vector<vector<int> > maps) {
	
	queue<P> q;
	q.push({ N - 1, M - 1 });
	check[N - 1][M - 1] = 1;

	while (!q.empty()) {
		P front = q.front(); q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = front.y + dy[k];
			int nx = front.x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (check[ny][nx] == 0 && maps[ny][nx] == 1) {
				q.push({ ny, nx });
				check[ny][nx] = check[front.y][front.x]+1;
			}
		}
	}
}

int solution(vector<vector<int> > maps)
{
	int answer = 0;
	
	N = maps.size();
	M = maps[0].size();

	bfs(maps);

	answer = check[0][0];
	if (answer == 0)
		answer = - 1;
	
	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} });

	//freopen("Text.txt", "r", stdin);


	return 0;
}