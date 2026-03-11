#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int n = temperaturesSize;
    int* ans = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && temperatures[i] >= temperatures[stack[top]]) {
            top--;
        }
        ans[i] = (top != -1) ? stack[top] - i : 0;
        stack[++top] = i;
    }

    *returnSize = n;
    free(stack);
    return ans;
}
