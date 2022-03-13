#include <cstdio>
using namespace std;

char str[10000][11];

struct Trie {
	bool finished;	// 문자열이 끝났는가
	bool append;
	Trie* letter[10];	// 0~9 문자가 뒤이어오는가
};

bool insert(Trie* cur, const char* pch) {
	if (*pch == '\0') {
		cur->finished = true;
		if (cur->append)
			return false;
		return true;
	}

	if (cur->finished)
		return false;

	cur->append = true;
	if (cur->letter[*pch - '0'] == NULL)
		cur->letter[*pch - '0'] = new Trie();
	return insert(cur->letter[*pch - '0'], pch + 1);
}

int main() {

	//freopen("Text.txt", "r", stdin);

	int T;
	scanf(" %d", &T);

	for (int tc = 0; tc < T; tc++) {
		int N;
		scanf(" %d", &N);

		Trie* root = new Trie();

		bool flag = true;
		for (int i = 0; i < N; i++) {
			scanf(" %s", str[i]);
			
			// 트라이에 추가
			if (!insert(root, str[i]))
				flag = false;
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}