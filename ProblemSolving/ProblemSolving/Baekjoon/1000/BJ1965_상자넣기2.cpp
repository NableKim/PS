/*
�迭 Arr�� �־����� ��
LIS[i] = Arr[i] ���Ҹ� ������ LIS ���� ����
	= max( LIS[0~(i-1)] ) + 1 
	= i ������ ���ҵ�� ���� �� �ִ� LIS�� ���ϰ�,
	  �� �ڿ� i��° ���Ҹ� ���Խ��������� ���̸� ���Ѵ�.
	  (��, i��° ���Ұ� ���������� Ŀ����) 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define BOX_NUM 1000

int LIS[BOX_NUM];
int B[BOX_NUM];

int main() {
	
	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %d", &B[i]);
	}

	for (int i = 0; i < N; i++) {
		LIS[i] = 1;
		for (int j = 0; j < i; j++) {
			if(B[j] < B[i])
				LIS[i] = max(LIS[i], LIS[j] + 1);
		}
	}

	int maxVal = 1;
	for (int i = 0; i < N; i++)
		maxVal = max(LIS[i], maxVal);

	printf("%d", maxVal);

	return 0;
}