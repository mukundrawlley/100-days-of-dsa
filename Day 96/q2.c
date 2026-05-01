#include <stdio.h>
#include <stdlib.h>

int countWhileMerge(int* nums, int left, int mid, int right) {
	int count = 0;
	int j = mid + 1;
	for (int i = left; i <= mid; i++) {
		while (j <= right && (long long)nums[i] > 2LL * nums[j]) j++;
		count += (j - (mid + 1));
	}
	return count;
}

void merge(int* nums, int left, int mid, int right) {
	int n = right - left + 1;
	int* temp = (int*)malloc(n * sizeof(int));
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (nums[i] <= nums[j]) temp[k++] = nums[i++];
		else temp[k++] = nums[j++];
	}
	while (i <= mid) temp[k++] = nums[i++];
	while (j <= right) temp[k++] = nums[j++];

	for (i = 0; i < n; i++) nums[left + i] = temp[i];
	free(temp);
}

int mergeSort(int* nums, int left, int right) {
	if (left >= right) return 0;
	int mid = left + (right - left) / 2;

	int count = mergeSort(nums, left, mid);
	count += mergeSort(nums, mid + 1, right);
	count += countWhileMerge(nums, left, mid, right);

	merge(nums, left, mid, right);
	return count;
}

