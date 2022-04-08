#include <cstdio>
using namespace std;

typedef struct _Node {
	int data;
	_Node* left;
	_Node* right;
} Node;

Node* AVL_pRoot;	// AVL Ʈ���� ��Ʈ ��忡 ���� ������

int max(int a, int b) {
	return a > b ? a : b;
}

// Ʈ���� ���̸� ��ȯ
int getHeight(Node** pParentNode) {
	if (*pParentNode == NULL)
		return 0;

	return 1 + max(getHeight(&((*pParentNode)->left)),
		getHeight(&((*pParentNode)->right)));

}

// ���� Ʈ���� ���� ���� ��ȯ
int getHeightDiff(Node** pParentNode) {
	if ((*pParentNode) == NULL) return 0;
	return getHeight(&((*pParentNode)->left)) - getHeight(&((*pParentNode)->right));
}

Node* rotate_LL(Node* parentNode) {
	Node* childNode = parentNode->left;
	parentNode->left = childNode->right;
	childNode->right = parentNode;
	return childNode;
}

Node* rotate_RR(Node* parentNode) {
	Node* childNode = parentNode->right;
	parentNode->right = childNode->left;
	childNode->left = parentNode;
	return childNode;
}

Node* rotate_LR(Node* parentNode) {
	parentNode->left = rotate_RR(parentNode->left);
	parentNode = rotate_LL(parentNode);
	return parentNode;
}

Node* rotate_RL(Node* parentNode) {
	parentNode->right = rotate_LL(parentNode->right);
	parentNode = rotate_RR(parentNode);
	return parentNode;
}

Node* rebalance(Node** pParentNode) {

	// ���� ���� Ʈ���� ���̿� ���� ���� Ʈ���� ���� �� Ȯ��
	int diff = getHeightDiff(pParentNode);

	if (diff > 1) {
		diff = getHeightDiff(&((*pParentNode)->left));
		
		if (diff > 0)	// LL
			(*pParentNode) = rotate_LL(*pParentNode);
		else // LR
			(*pParentNode) = rotate_LR(*pParentNode);
	}
	else if (diff < -1) {
		diff = getHeightDiff(&((*pParentNode)->right));

		if (diff < 0) // RR
			(*pParentNode) = rotate_RR(*pParentNode);
		
		else // RL
			(*pParentNode) = rotate_RL(*pParentNode);
	}
	
	return (*pParentNode);
}

// AVL Ʈ���� ���ο� �� �߰�
Node* addNewNode(Node** pParentNode, int value) {
	if((*pParentNode) == NULL) {
		// ���ο� ��带 �����
		Node* pNewNode = new Node;
		pNewNode->data = value;
		pNewNode->left = pNewNode->right = NULL;

		// ���ο� ��带 �θ��� �ڽ� ���� ����
		(*pParentNode) = pNewNode;
	}
	else if ((*pParentNode)->data < value) {	// �θ� ��庸�� ū ���� ���
		(*pParentNode)->right = addNewNode(&((*pParentNode)->right), value);
		(*pParentNode) = rebalance(pParentNode);
	}
	else if ((*pParentNode)->data > value) {	// �θ� ��庸�� ���� ���� ���
		(*pParentNode)->left = addNewNode(&((*pParentNode)->left), value);
		(*pParentNode) = rebalance(pParentNode);
	}
	else {
		printf("ERROR : �ߺ��� ���� ����\n");
		return NULL;
	}
	return (*pParentNode);

}


int main() {

	addNewNode(&AVL_pRoot, 8);
	addNewNode(&AVL_pRoot, 9);
	addNewNode(&AVL_pRoot, 10);
	addNewNode(&AVL_pRoot, 2);
	addNewNode(&AVL_pRoot, 1);
	addNewNode(&AVL_pRoot, 5);
	addNewNode(&AVL_pRoot, 3);
	addNewNode(&AVL_pRoot, 6);
	addNewNode(&AVL_pRoot, 4);
	addNewNode(&AVL_pRoot, 7);
	addNewNode(&AVL_pRoot, 11);
	addNewNode(&AVL_pRoot, 12);

	return 0;
}