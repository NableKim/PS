#include <cstdio>
using namespace std;

typedef struct _AVL_NODE {
	int data;	// 노드의 데이터
	int height;	// 트리의 높이
	_AVL_NODE* left, * right;	// 왼쪽, 오른쪽 자식 포인터

	_AVL_NODE(int value) {
		data = value;
		height = 1;
		left = right = NULL;
	}
} NODE;

NODE* ptrAvlRoot = NULL;	// AVL 트리의 루트 노드를 가리키는 포인터

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

	A->left = B->right; // 자식 노드의 오른쪽 서브트리를 부모 노드의 왼쪽 서브트리로
	B->right = A;		// 부모 노드를 자식 노드의 오른쪽 노드로 설정

	// A, B노드의 높이 갱신
	A->height = 1 + max(getTreeHeight(A->left), getTreeHeight(A->right));
	B->height = 1 + max(getTreeHeight(B->left), getTreeHeight(B->right));

	// 회전 결과 B가 새로운 루트 노드로 변경
	return B;
}

NODE* rotate_RR(NODE* ptrParentNode) {

	NODE* A = ptrParentNode;
	NODE* B = ptrParentNode->right;

	A->right = B->left; // 자식 노드의 왼쪽 서브트리를 부모 노드의 오른쪽 서브트리로
	B->left = A;		// 부모 노드를 자식 노드의 왼쪽 노드로 설정

	// A, B노드의 높이 갱신
	A->height = 1 + max(getTreeHeight(A->left), getTreeHeight(A->right));
	B->height = 1 + max(getTreeHeight(B->left), getTreeHeight(B->right));

	// 회전 결과 B가 새로운 루트 노드로 변경
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

	// BF값 측정
	int bf = getTreeHeight(ptrParentNode->left) 
		- getTreeHeight(ptrParentNode->right);

	if (bf > 1) {	// 왼쪽 서브트리가 비대해진 경우
		
		bf = getTreeHeight(ptrParentNode->left->left)
			- getTreeHeight(ptrParentNode->left->right);

		if (bf > 0) {	// LL 
			ptrParentNode = rotate_LL(ptrParentNode);
		}
		else {	// LR
			ptrParentNode = rotate_LR(ptrParentNode);
		}

	}
	else if (bf < -1) {	// 오른쪽 서브트리가 비대해진 경우

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
		// 새로운 노드 생성
		return new NODE(value);
	}
	else if (ptrParentNode->data < value) {
		ptrParentNode->right = insertNode(ptrParentNode->right, value);
	}
	else if (ptrParentNode->data > value) {
		ptrParentNode->left = insertNode(ptrParentNode->left, value);
	}
	else {
		printf("ERROR : 중복된 값을 넣으려고 하고 있습니다.");
		return NULL;
	}

	// ptrParentNode의 높이값을 갱신
	ptrParentNode->height = 1 + max(getTreeHeight(ptrParentNode->left),
		getTreeHeight(ptrParentNode->right));

	// 균형 있는 트리를 유지하기 위한 점검
	ptrParentNode = rebalance(ptrParentNode);

	return ptrParentNode;
}

int main() {

	// AVL 트리에 노드를 추가하는 함수
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