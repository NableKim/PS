// 6 이라는 수는 배열의 몇번째 인덱스에 존재할까?

#include <cstdio>
using namespace std;

#define ARR_SIZE 10

int binary_search(int* arr, int target) {

	int index = -1;
	int left = 0;
	int right = ARR_SIZE - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target)
			return mid;	// target을 찾은 경우
		else if (arr[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;	// target을 찾지 못한 경우
}

int main() {
	int arr[ARR_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target = 6;

	printf("%d는 배열의 %d 번째 index에 존재합니다.", target, binary_search(arr, target));
	
	return 0;
}