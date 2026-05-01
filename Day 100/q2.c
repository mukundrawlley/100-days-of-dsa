#include <stdio.h>
#include <stdlib.h>

struct Item {
    int val;
    int index;
};

void merge(struct Item* items, int left, int mid, int right, int* count, struct Item* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0; 

    while (i <= mid && j <= right) {
        if (items[j].val < items[i].val) {
            rightCount++;
            temp[k++] = items[j++];
        } else {
            count[items[i].index] += rightCount;
            temp[k++] = items[i++];
        }
    }

    while (i <= mid) {
        count[items[i].index] += rightCount;
        temp[k++] = items[i++];
    }
    while (j <= right) {
        temp[k++] = items[j++];
    }

    for (i = left; i <= right; i++) {
        items[i] = temp[i];
    }
}
void mergeSort(struct Item* items, int left, int right, int* count, struct Item* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(items, left, mid, count, temp);
        mergeSort(items, mid + 1, right, count, temp);
        merge(items, left, mid, right, count, temp);
    }
}


