#include <cstdio>
using namespace std;

typedef struct _AVL_NODE {
	int data;	// ����� ������
	int height;	// Ʈ���� ����
	_AVL_NODE* left, * right;	// ����, ������ �ڽ� ������

	_AVL_NODE(int value) {
		data = value;
		height = 1;
		left = right = NULL;
	}
} NODE;

NODE* ptrAvlRoot = NULL;	// AVL Ʈ���� ��Ʈ ��带 ����Ű�� ������

int max(int a, int b) {
	return a > b ? a : b;
}

int getTreeHeight(NODE* ptrNode) {
	if (ptrNode == NULL)
		return 0;
	return ptrNode->height;
}

NODE* rotate_LL(NODE* ptrParentNode) {

	NODE* A = ptrParentNode;
	NODE* B = ptrParentNode->left;

	A->left = B->right; // �ڽ� ����� ������ ����Ʈ���� �θ� ����� ���� ����Ʈ����
	B->right = A;		// �θ� ��带 �ڽ� ����� ������ ���� ����

	// A, B����� ���� ����
	A->height = 1 + max(getTreeHeight(A->left), getTreeHeight(A->right));
	B->height = 1 + max(getTreeHeight(B->left), getTreeHeight(B->right));

	// ȸ�� ��� B�� ���ο� ��Ʈ ���� ����
	return B;
}

NODE* rotate_RR(NODE* ptrParentNode) {

	NODE* A = ptrParentNode;
	NODE* B = ptrParentNode->right;

	A->right = B->left; // �ڽ� ����� ���� ����Ʈ���� �θ� ����� ������ ����Ʈ����
	B->left = A;		// �θ� ��带 �ڽ� ����� ���� ���� ����

	// A, B����� ���� ����
	A->height = 1 + max(getTreeHeight(A->left), getTreeHeight(A->right));
	B->height = 1 + max(getTreeHeight(B->left), getTreeHeight(B->right));

	// ȸ�� ��� B�� ���ο� ��Ʈ ���� ����
	return B;
}

NODE* rotate_LR(NODE* ptrParentNode) {
	NODE* A = ptrParentNode;
	NODE* B = ptrParentNode->left;

	A->left = rotate_RR(B);
	return rotate_LL(A);
}

NODE* rotate_RL(NODE* ptrParentNode) {
	NODE* A = ptrParentNode;
	NODE* B = ptrParentNode->right;

	A->right = rotate_LL(B);
	return rotate_RR(A);
}

NODE* rebalance(NODE* ptrParentNode) {

	// BF�� ����
	int bf = getTreeHeight(ptrParentNode->left) 
		- getTreeHeight(ptrParentNode->right);

	if (bf > 1) {	// ���� ����Ʈ���� ������� ���
		
		bf = getTreeHeight(ptrParentNode->left->left)
			- getTreeHeight(ptrParentNode->left->right);

		if (bf > 0) {	// LL 
			ptrParentNode = rotate_LL(ptrParentNode);
		}
		else {	// LR
			ptrParentNode = rotate_LR(ptrParentNode);
		}

	}
	else if (bf < -1) {	// ������ ����Ʈ���� ������� ���

		bf = getTreeHeight(ptrParentNode->right->left)
			- getTreeHeight(ptrParentNode->right->right);

		if (bf > 0) {	// RL
			ptrParentNode = rotate_RL(ptrParentNode);
		}
		else {	// RR
			ptrParentNode = rotate_RR(ptrParentNode);
		}
	}

	return ptrParentNode;
}

NODE* insertNode(NODE* ptrParentNode, int value) {

	if (ptrParentNode == NULL) {
		// ���ο� ��� ����
		return new NODE(value);
	}
	else if (ptrParentNode->data < value) {
		ptrParentNode->right = insertNode(ptrParentNode->right, value);
	}
	else if (ptrParentNode->data > value) {
		ptrParentNode->left = insertNode(ptrParentNode->left, value);
	}
	else {
		printf("ERROR : �ߺ��� ���� �������� �ϰ� �ֽ��ϴ�.");
		return NULL;
	}

	// ptrParentNode�� ���̰��� ����
	ptrParentNode->height = 1 + max(getTreeHeight(ptrParentNode->left),
		getTreeHeight(ptrParentNode->right));

	// ���� �ִ� Ʈ���� �����ϱ� ���� ����
	ptrParentNode = rebalance(ptrParentNode);

	return ptrParentNode;
}

int main() {

	// AVL Ʈ���� ��带 �߰��ϴ� �Լ�
	ptrAvlRoot = insertNode(ptrAvlRoot, 8);
	ptrAvlRoot = insertNode(ptrAvlRoot, 9);
	ptrAvlRoot = insertNode(ptrAvlRoot, 10);
	ptrAvlRoot = insertNode(ptrAvlRoot, 2);
	ptrAvlRoot = insertNode(ptrAvlRoot, 1);
	ptrAvlRoot = insertNode(ptrAvlRoot, 5);
	ptrAvlRoot = insertNode(ptrAvlRoot, 3);
	ptrAvlRoot = insertNode(ptrAvlRoot, 6);
	ptrAvlRoot = insertNode(ptrAvlRoot, 4);
	ptrAvlRoot = insertNode(ptrAvlRoot, 7);
	ptrAvlRoot = insertNode(ptrAvlRoot, 11);
	ptrAvlRoot = insertNode(ptrAvlRoot, 12);

	return 0;
}