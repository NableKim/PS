#include <cstdio>
using namespace std;

#define MAX_NODE 1000

int PREO[MAX_NODE];
int INO[MAX_NODE];

typedef struct _Node {
	int val;
	_Node* left;
	_Node* right;
} Node;

Node* ptr_root;

void postOrder(Node* root) {
	if (root == NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->val);
}

Node* dfs(int pre_left, int pre_right, int in_left, int in_right) {

	if (in_right - in_left < 0)
		return NULL;

	Node* newNode = new Node();
	newNode->val = PREO[pre_left];
	newNode->left = NULL;
	newNode->right = NULL;

	if (in_right - in_left > 0) {
		int newRootIdx;
		for (newRootIdx = in_left; newRootIdx <= in_right; newRootIdx++) {
			if (PREO[pre_left] == INO[newRootIdx])
				break;
		}

		int len = newRootIdx - in_left;
		newNode->left = dfs(pre_left + 1, pre_left + len, in_left, newRootIdx - 1);
		newNode->right = dfs(pre_left + len + 1, pre_right, newRootIdx + 1, in_right);
	}

	return newNode;
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int T;
	scanf(" %d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf(" %d", &N);

		for (int i = 0; i < N; i++) {
			scanf(" %d", &PREO[i]);
		}

		for (int i = 0; i < N; i++) {
			scanf(" %d", &INO[i]);
		}

		ptr_root = dfs(0, N - 1, 0, N - 1);

		postOrder(ptr_root);
		printf("\n");
	}

	
}