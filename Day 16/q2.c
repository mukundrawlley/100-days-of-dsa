void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;

    k = k % numsSize;   // handle k > size
    
    reverse(nums, 0, numsSize - 1);      // reverse whole array
    reverse(nums, 0, k - 1);             // reverse first k elements
    reverse(nums, k, numsSize - 1);      // reverse remaining elements
}
