#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += nums[i];
    }
    return expectedSum - actualSum;
}

int main() {
    int nums[] = {3, 0, 1};
    int size = sizeof(nums)/sizeof(nums[0]);
    printf("Missing number: %d\n", missingNumber(nums, size));
    return 0;
}
