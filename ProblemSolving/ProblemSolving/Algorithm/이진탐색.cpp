#include <iostream>
#include <cstdio>
using namespace std;

int arr[] = { 1, 4, 4, 5, 5, 6, 7 };

int upper_bound(int left, int right, int target) {

	while (left <= right) {
		int mid = left + right;
		mid /= 2;

		if (target <= arr[mid] )
			right = mid - 1;
		else 
			left = mid + 1;
	}
	return right;
}

int lower_bound(int left, int right, int target) {

	while (left <= right) {
		int mid = left + right;
		mid /= 2;

		if (target <= arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right+1;
}

int main() {

	cout << upper_bound(0, 6, 5);	// 5 미만인 최초 지점
	cout << endl;
	cout << lower_bound(0, 6, 5);	// 5 이상인 최초 지점

	return 0;
}