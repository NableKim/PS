#include <cstdio>
using namespace std;

typedef struct _Node {
	int data;
	_Node* left;
	_Node* right;
} Node;

Node* AVL_pRoot;	// AVL 트리의 루트 노드에 대한 포인터

int max(int a, int b) {
	return a > b ? a : b;
}

// 트리의 높이를 반환
int getHeight(Node** pParentNode) {
	if (*pParentNode == NULL)
		return 0;

	return 1 + max(getHeight(&((*pParentNode)->left)),
		getHeight(&((*pParentNode)->right)));

}

// 서브 트리의 높이 차이 반환
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

	// 왼쪽 서브 트리의 높이와 오른 서브 트리의 높이 차 확인
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

// AVL 트리에 새로운 값 추가
Node* addNewNode(Node** pParentNode, int value) {
	if((*pParentNode) == NULL) {
		// 새로운 노드를 만들고
		Node* pNewNode = new Node;
		pNewNode->data = value;
		pNewNode->left = pNewNode->right = NULL;

		// 새로운 노드를 부모의 자식 노드로 설정
		(*pParentNode) = pNewNode;
	}
	else if ((*pParentNode)->data < value) {	// 부모 노드보다 큰 값인 경우
		(*pParentNode)->right = addNewNode(&((*pParentNode)->right), value);
		(*pParentNode) = rebalance(pParentNode);
	}
	else if ((*pParentNode)->data > value) {	// 부모 노드보다 작은 값인 경우
		(*pParentNode)->left = addNewNode(&((*pParentNode)->left), value);
		(*pParentNode) = rebalance(pParentNode);
	}
	else {
		printf("ERROR : 중복된 값이 들어옴\n");
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