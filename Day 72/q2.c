#include <limits.h>
#include <string.h>

int dp[15][1 << 15];

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int mask, int pos, int n, int cost[][20]) {

    if(mask == (1 << n) - 1)
        return cost[pos][0];

    if(dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INT_MAX;

    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {

            int newAns = cost[pos][city] +
                         solve(mask | (1 << city), city, n, cost);

            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}

/* GFG Expected Function */
int total_cost(int cost[][20], int n) {
    memset(dp, -1, sizeof(dp));
    return solve(1, 0, n, cost);
}
