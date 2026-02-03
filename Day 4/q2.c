#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

int main() {
    int nums[] = {3, 2, 2, 3, 4};
    int size = sizeof(nums)/sizeof(nums[0]);
    int val = 3;
    int newLength = removeElement(nums, size, val);
    printf("New array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nNew length: %d\n", newLength);
    return 0;
}
