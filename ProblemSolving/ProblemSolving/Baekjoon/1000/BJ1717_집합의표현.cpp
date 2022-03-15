#include <cstdio>
using namespace std;

int parent[1000001];

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void set_union(int a, int b) {

	int pa = getParent(a);
	int pb = getParent(b);

	if (pa > pb)
		parent[pa] = pb;
	else
		parent[pb] = pa;
}

bool same_union(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);
	return (pa == pb);
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N, M;
	scanf(" %d %d", &N, &M);

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf(" %d %d %d", &a, &b, &c);
		
		if (a == 0) {
			set_union(b, c);
		}
		else {
			if (same_union(b, c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}