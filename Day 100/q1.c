#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 20005

void update(int* bit, int index, int val) {
    while (index < MAX_VAL) {
        bit[index] += val;
        index += index & (-index);
    }
}

int query(int* bit, int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* count = (int*)malloc(numsSize * sizeof(int));
    
    int bit[MAX_VAL] = {0};

    for (int i = numsSize - 1; i >= 0; i--) {
        
        int shiftedNum = nums[i] + 10001;
        
        count[i] = query(bit, shiftedNum - 1);
        
        update(bit, shiftedNum, 1);
    }

    return count;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i < size - 1) ? "," : "");
    }
    printf("]\n");
}

int main() {
    int nums1[] = {5, 2, 6, 1};
    int returnSize1;
    int* res1 = countSmaller(nums1, 4, &returnSize1);
    printf("Input: [5, 2, 6, 1]\nOutput: ");
    printArray(res1, returnSize1);
    free(res1);

    int nums2[] = {-1};
    int returnSize2;
    int* res2 = countSmaller(nums2, 1, &returnSize2);
    printf("Input: [-1]\nOutput: ");
    printArray(res2, returnSize2);
    free(res2);

    int nums3[] = {-1, -1};
    int returnSize3;
    int* res3 = countSmaller(nums3, 2, &returnSize3);
    printf("Input: [-1, -1]\nOutput: ");
    printArray(res3, returnSize3);
    free(res3);

    return 0;
}
