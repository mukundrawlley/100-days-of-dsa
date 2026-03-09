#include <stdio.h>

#define MAX 10000

int deque[MAX];
int front = 0, rear = -1;

int isEmpty() {
    return front > rear;
}

void popFront() {
    front++;
}

void popBack() {
    rear--;
}

void pushBack(int x) {
    deque[++rear] = x;
}

int getFront() {
    return deque[front];
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    int result[n];
    int resSize = 0;

    for (int i = 0; i < n; i++) {
        /* Remove indices out of current window */
        if (!isEmpty() && getFront() <= i - k)
            popFront();

        /* Remove smaller elements */
        while (!isEmpty() && nums[deque[rear]] < nums[i])
            popBack();

        pushBack(i);

        /* Store result once first window is complete */
        if (i >= k - 1)
            result[resSize++] = nums[getFront()];
    }

    /* Print result */
    for (int i = 0; i < resSize; i++)
        printf("%d ", result[i]);

    return 0;
}
