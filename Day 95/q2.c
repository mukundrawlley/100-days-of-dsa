#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
	if (numsSize < 2) return 0;

	int minVal = INT_MAX, maxVal = INT_MIN;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < minVal) minVal = nums[i];
		if (nums[i] > maxVal) maxVal = nums[i];
	}

	int gap = (maxVal - minVal + numsSize - 2) / (numsSize - 1);
	int bucketCount = numsSize - 1;

	int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
	int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

	for (int i = 0; i < bucketCount; i++) {
		bucketMin[i] = INT_MAX;
		bucketMax[i] = INT_MIN;
	}

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == minVal || nums[i] == maxVal) continue;
		int idx = (nums[i] - minVal) / gap;
		if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
		if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
	}

	int maxGap = 0;
	int prev = minVal;
	for (int i = 0; i < bucketCount; i++) {
		if (bucketMin[i] == INT_MAX) continue;
		if (bucketMin[i] - prev > maxGap) maxGap = bucketMin[i] - prev;
		prev = bucketMax[i];
	}

	if (maxVal - prev > maxGap) maxGap = maxVal - prev;

	free(bucketMin);
	free(bucketMax);

	return maxGap;
}

