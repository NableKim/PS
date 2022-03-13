#include <cstdio>
using namespace std;

// �� ��带 ������ ���ڿ��� ��������°�
// ���̾� �� ���� ������ ����(0~9 ���� ���ڸ� �޴´ٰ� ����)

// ������ �޼ҵ�
	// �߰��ϱ�
	// prefix �˻�
	// Ư�� ���ڿ��� �����ϴ°�

struct TRIE {
	bool finished;
	TRIE* letter[10];	// 0~9 ���� ���ڸ� �� �� ����
};

void insert(TRIE* cur, const char* pch) {
	// ���ڿ��� ���� �����ٸ�
	if (*pch == '\0') {
		cur->finished = true;
		return;
	}

	if (cur->letter[*pch - '0'] == NULL)
		cur->letter[*pch - '0'] = new TRIE();
	insert(cur->letter[*pch - '0'], pch + 1);
}

bool prefixExist(TRIE* cur, const char* pch) {
	if (*pch == '\0')
		return true;

	if (cur->letter[*pch - '0'] == NULL)
		return false;
	return prefixExist(cur->letter[*pch - '0'], pch + 1);
}

bool ExistString(TRIE* cur, const char* pch) {
	if (*pch == '\0') {
		if (cur->finished) return true;
		return false;
	}

	if (cur->letter[*pch - '0'] == NULL)
		return false;
	return ExistString(cur->letter[*pch - '0'], pch + 1);
}

int main() {

	TRIE* root = new TRIE();

	const char* str[2] = { "12", "123" };
	insert(root, str[0]);
	insert(root, str[1]);

	if (prefixExist(root, "3"))
		printf("prefix����");
	else
		printf("prefix������");

	if (ExistString(root, "123"))
		printf("string����");
	else
		printf("string������");

	return 0;
}