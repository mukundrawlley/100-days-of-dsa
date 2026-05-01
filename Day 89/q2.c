#include <stdbool.h>

void findMaxNSum(int* weights, int size, int* low, int* high) {
    for (int i = 0; i < size; i++) {
        if (*low > weights[i]) *low = weights[i];
        *high += weights[i];
    }
}

bool findMinWeights(int* weights, int size, int days, int minWeight) {
    int temp = minWeight;
    int i = 0;
    while (i < size && days > 0) {
        if (temp < weights[i]) {
            days--;
            temp = minWeight;
        } else {
            temp -= weights[i];
            i++;
        }
    }
    return i == size;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0, ans = 0;
    findMaxNSum(weights, weightsSize, &low, &high);
    while (low <= high) {
        int mid = (low + high) / 2;
        if (findMinWeights(weights, weightsSize, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}