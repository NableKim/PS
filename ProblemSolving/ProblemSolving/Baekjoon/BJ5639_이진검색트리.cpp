#include <cstdio>
using namespace std;

typedef struct NODE {
	int value;
	NODE* left;
	NODE* right;
	NODE(int value, NODE* left, NODE* right) : value(value), left(left), right(right) {}
} Node;

Node* ptr_root;

void insertNode(Node* newNode) {
	
	if (ptr_root == NULL) {
		ptr_root = newNode;
		return;
	}

	Node* newPosition = ptr_root;
	
	while (1) {
		if (newNode->value < newPosition->value) {
			if (newPosition->left == NULL) {
				newPosition->left = newNode;
				break;
			}
			newPosition = newPosition->left;
		}
		else {
			if (newPosition->right == NULL) {
				newPosition->right = newNode;
				break;
			}
			newPosition = newPosition->right;
		}
	}
}

void postOrder(Node* ptr) {
	if (ptr == NULL) return;
	postOrder(ptr->left);
	postOrder(ptr->right);
	printf("%d\n", ptr->value);
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int n;
	ptr_root = NULL;
	while (scanf("%d", &n) != EOF) {
		Node* newNode = new Node(n, NULL, NULL);
		insertNode(newNode);
	}

	postOrder(ptr_root);

	return 0;
}