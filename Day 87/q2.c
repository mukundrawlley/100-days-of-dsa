#include <limits.h>

long long computeHours(int* piles, int n, int speed) {
    long long hours = 0;
    for(int i = 0; i < n; i++) {
        hours += (piles[i] + speed - 1) / speed;
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1, high = 0;

    for(int i = 0; i < pilesSize; i++) {
        if(piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        long long totalHours = computeHours(piles, pilesSize, mid);

        if(totalHours <= (long long)h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
