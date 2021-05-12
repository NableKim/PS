#include <cstdio>

int ans;

int strlen(const char* s) {
	int len = 0;
	while (*s++)
		len++;
	return len;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm_recursive(int* num, int n, int m, int depth) {

	// m번 뒤집었다면
	if (depth == m) {
		//printArray(num);

		// 현재 num을 기준으로 합 구하기
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum *= 10;
			sum += num[i];
		}

		ans = sum > ans ? sum : ans;
		return;
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(&num[i], &num[j]);	// i 자리에 j번째 수가 위치
			perm_recursive(num, n, m, depth + 1);
			swap(&num[i], &num[j]);
		}
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);
	
	int tc;

	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		char str[7] = { 0, };
		int num[7] = { 0, };
		int r;

		ans = 0;
		scanf("%s %d", str, &r);

		int len = strlen(str);

		for (int i = 0; i < len; i++)
			num[i] = str[i] - '0';

		if (len < r)
			r = len;

		// num을 가지고 순열 구하기
		perm_recursive(num, len, r, 0);	// len P r 

		printf("#%d %d\n", t, ans);
	}

	return 0;
}