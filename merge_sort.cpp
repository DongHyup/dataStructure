#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define ARR_MAX 8
int sorted[ARR_MAX] = {0,};

void merge(int* target, int left, int mid, int right) {
	int l_idx = left;	//mid를 기준으로 왼쪽리스트의 첫번째 인덱스
	int r_idx = mid + 1; //mid를 기준으로 오른쪽리스트의 첫번째 인덱스
	int cur_idx = left;  //정렬하는 리스트의 첫번재 인덱스
	
	while (l_idx <= mid && r_idx <= right) {
		if (target[l_idx] <= target[r_idx]) {
			sorted[cur_idx] = target[l_idx];
			cur_idx++; l_idx++;
		}
		else {
			sorted[cur_idx] = target[r_idx];
			cur_idx++; r_idx++;
		}
	}

	//나머지 남은 것들을 왼쪽 리스트에 모두 넣어줌
	if (l_idx<=mid) {
		for (int i = l_idx; i <= mid; i++) {
			sorted[cur_idx] = target[i];
			cur_idx++;
		}
	}

	//나머지 남은 것들을 오른쪽 리스트에 모두 넣어줌
	else {
		for (int i = r_idx; i <= right; i++) {
			sorted[cur_idx] = target[i];
			cur_idx++;
		}
	}

	//원본 배열에 정렬한 값을 다시 넣음
	for (int i = left; i <= right; i++) {
		target[i] = sorted[i];
	}

}

void merge_sort(int* target, int left, int right) {

	if (left < right) {
		int mid = (int)((left+right)/2);
		merge_sort(target, left, mid);
		merge_sort(target, mid + 1, right);
		merge(target, left, mid, right);
	}

}

int main(int argc, char *argv[], char *env[]) {

	int arr[ARR_MAX] = { 21, 10, 12, 20, 25, 13, 15, 22 };

	merge_sort(arr, 0, ARR_MAX - 1);

	for (int i = 0; i<ARR_MAX; i++)
		printf("%d\n", arr[i]);

	return 0;
}
