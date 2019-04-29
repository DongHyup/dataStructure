#include <stdio.h>
#include <iostream>

using namespace std;

#define ARR_MAX 9

bool swap(int* first, int* second) {
	try {
		int temp = *first;
		*first = *second;
		*second = temp;
		return true;
	}
	catch (const exception& ex){
		cout << ex.what() << endl;
		return false;
	}

	return false;
}

int partition(int* target, int left, int right) {
	int pivot=0;
	int low=0, high=0;

	low = left;
	high = right;
	pivot = target[left];

	do {
		do {
			low++;
		} while (low <= right && target[low] < pivot);
		do {
			high--;
		} while (high >= left && target[high] > pivot);
		
		if (low < high)
			swap(&target[low], &target[high]);

	} while (low < high);

	swap(&target[left], &target[high]);

	return high;
}

void quick_sort(int* target, int left, int right) {

	if (left < right) {
		int q = partition(target, left, right);
		quick_sort(target, left, q-1);
		quick_sort(target, q + 1, right);
	}

}

int main(int argc, char *argv[], char *env[]) {

	int i;
	int arr[ARR_MAX] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };

	// 퀵 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 8)
	quick_sort(arr, 0, ARR_MAX - 1);

	// 정렬 결과 출력
	for (i = 0; i<ARR_MAX; i++)
		printf("%d ", arr[i]);

}
