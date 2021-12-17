#include <cstdio>
#include <queue>
using namespace std;

#define MAX_NODE 100001
#define INF 100001

struct P {
	int loc, t;
};

priority_queue<P> q;
int N, K;
int check[MAX_NODE];

bool operator<(P a, P b) {
	return a.t > b.t;
}

void bfs() {

	check[N] = 0;
	q.push({ N, 0 });

	while (!q.empty()) {
		P front = q.top(); q.pop();
		if (front.loc == K)
			break;
	
		int nextLoc;
		nextLoc = front.loc - 1;
		if (0 <= nextLoc  && check[nextLoc] > front.t + 1) {
			q.push({ nextLoc, front.t + 1 });
			check[nextLoc] = front.t + 1;
		}

		nextLoc = front.loc + 1;
		if (nextLoc < MAX_NODE && check[nextLoc] > front.t + 1) {
			q.push({ nextLoc, front.t + 1 });
			check[nextLoc] = front.t + 1;
		}

		nextLoc = front.loc * 2;
		if (nextLoc < MAX_NODE && check[nextLoc] > front.t) {
			q.push({ nextLoc, front.t });
			check[nextLoc] = front.t;
		}
	}
}

int main() {
	
	//freopen("Text.txt", "r", stdin);

	scanf(" %d %d", &N, &K);

	for (int i = 0; i < MAX_NODE; i++)
		check[i] = INF;

	bfs();
	
	printf("%d", check[K]);
	
	return 0;
}