int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int* pos, int n, int m, int minDist) {
    int count = 1;
    int lastPos = pos[0];

    for(int i = 1; i < n; i++) {
        if(pos[i] - lastPos >= minDist) {
            count++;
            lastPos = pos[i];
        }

        if(count >= m)
            return 1;
    }

    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compare);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canPlace(position, positionSize, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
