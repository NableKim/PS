// 80 이상이면서 가장 낮은 수는?

#include <cstdio>
using namespace std;

#define ARR_SIZE 10

int binary_search(int* arr, int target) {
	int left = 0;
	int right = ARR_SIZE - 1;

	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target)
			return mid;	// target을 찾은 경우
		else if (arr[mid] > target)
			right = mid;
		else
			left = mid+1;
	}
	return left;
}

int main() {
	int arr[ARR_SIZE] = { 10, 23, 34, 48, 59, 62, 77, 81, 96, 100 };
	int target = 80;

	int index = binary_search(arr, target);
	if (index)
		printf("80점 이상이면서 가장 낮은 수는 %d 입니다.", arr[index]);

	return 0;
}