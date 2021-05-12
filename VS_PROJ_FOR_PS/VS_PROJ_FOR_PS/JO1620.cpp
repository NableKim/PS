#include <cstdio>

int strlen(const char* str) {
	int len = 0;
	while (*str++) len++;
	return len;
}

void reverse(char* str) {
	for (int i = 0; i < 2; i++) {
		char tmp = str[i];
		str[i] = str[3 - i];
		str[3 - i] = tmp;
	}
}

int main() {

	freopen("Text.txt", "r", stdin);

	char str[101] = { 0, };
	int n1, n2;

	scanf("%s", str);
	scanf(" %d %d", &n1, &n2);

	// Step 1. str에서 -을 기준으로 숫자 배열을 생성한다

	// str의 문자열 길이를 구한다.
	int sSize = strlen(str);

	char num[50][101] = { 0, };	// 숫자 배열
	int dummyCnt = 0;		// 숫자 더미 개수
	int cnt = 0;			// 한 숫자 더미 안의 자리수
	bool err = false;
	for (int i = sSize-1; i >= 0 ; i--) {
		if (str[i] == '-') {
			if (cnt > 4) {		// 4자리 초과인 경우
				err = true;
				break;
			}
			else if (cnt < 4) {	// 4 자리 이하인 경우
				for(int j=cnt; j<4; j++)
					num[dummyCnt][cnt++] = '0';
			}
			reverse(num[dummyCnt]);
			dummyCnt++;
			cnt = 0;
		}
		else
			num[dummyCnt][cnt++] = str[i];
	}
	if (cnt) {	// 숫자로 끝난 경우
		if (cnt > 4)		// 4자리 초과인 경우
			err = true;
		else if (cnt <= 4) {	// 4 자리 이하인 경우
			for (int j = cnt; j < 4; j++)
				num[dummyCnt][cnt++] = '0';
			reverse(num[dummyCnt]);
			dummyCnt++;
		}
	}
	
	if (dummyCnt < n2)
		err = true;

	if (err)
		printf("INPUT ERROR!");
	else {
		// Step 2. 원하는 숫자 더미의 각 자리에 n1을 더한다
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int tmp = (num[dummyCnt-n2][j] - '0') + n1;
			char ch = (tmp % 10) + '0';
			num[dummyCnt - n2][j] = ch;
		}
		printf("%s", num[dummyCnt - n2]);
	}
	
	return 0;
}