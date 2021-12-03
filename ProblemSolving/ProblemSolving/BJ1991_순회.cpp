#include <cstdio>
using namespace std;

#define NODE_MAX 26

int E[NODE_MAX][2];

void preOrder(int root) {
	if (root == -1)
		return;

	printf("%c", root + 'A');
	preOrder(E[root][0]);
	preOrder(E[root][1]);
}

void inOrder(int root) {
	if (root == -1)
		return;

	inOrder(E[root][0]);
	printf("%c", root + 'A');
	inOrder(E[root][1]);
}

void postOrder(int root) {
	if (root == -1)
		return;

	postOrder(E[root][0]);
	postOrder(E[root][1]);
	printf("%c", root + 'A');
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	char p, l, r;
	while (N--) {
		scanf(" %c %c %c", &p, &l, &r);

		if (l != '.')
			E[p - 'A'][0] = l - 'A';
		else
			E[p - 'A'][0] = -1;

		if (r != '.')
			E[p - 'A'][1] = r - 'A';
		else	   
			E[p - 'A'][1] = -1;
	}

	preOrder(0);
	printf("\n");
	inOrder(0);
	printf("\n");
	postOrder(0);


	return 0;
}