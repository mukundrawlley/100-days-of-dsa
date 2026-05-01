#include <stdlib.h>

static int compareRelative(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
	int* result = (int*)malloc(sizeof(int) * arr1Size);
	int used[arr1Size];
	for (int i = 0; i < arr1Size; i++) used[i] = 0;

	int idx = 0;

	for (int i = 0; i < arr2Size; i++) {
		for (int j = 0; j < arr1Size; j++) {
			if (!used[j] && arr1[j] == arr2[i]) {
				result[idx++] = arr1[j];
				used[j] = 1;
			}
		}
	}

	int remaining[arr1Size];
	int remIdx = 0;
	for (int i = 0; i < arr1Size; i++) {
		if (!used[i]) remaining[remIdx++] = arr1[i];
	}

	qsort(remaining, remIdx, sizeof(int), compareRelative);
	for (int i = 0; i < remIdx; i++) result[idx++] = remaining[i];

	*returnSize = arr1Size;
	return result;
}

