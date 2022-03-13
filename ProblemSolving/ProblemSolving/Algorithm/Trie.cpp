#include <cstdio>
using namespace std;

// 이 노드를 끝으로 문자열이 만들어지는가
// 뒤이어 올 문자 정보를 저장(0~9 사이 문자만 받는다고 가정)

// 구현할 메소드
	// 추가하기
	// prefix 검사
	// 특정 문자열이 존재하는가

struct TRIE {
	bool finished;
	TRIE* letter[10];	// 0~9 사이 문자만 올 수 있음
};

void insert(TRIE* cur, const char* pch) {
	// 문자열의 끝을 만났다면
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
		printf("prefix존재");
	else
		printf("prefix미존재");

	if (ExistString(root, "123"))
		printf("string존재");
	else
		printf("string미존재");

	return 0;
}