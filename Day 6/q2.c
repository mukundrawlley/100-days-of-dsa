#include <stdio.h>

void moveZeroes(int* nums, int size) {
    int slow = 0;

    for (int fast = 0; fast < size; fast++) {
        if (nums[fast] != 0) {
            int temp = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = temp;
            slow++;
        }
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, size);

    printf("Array after moving zeros: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
