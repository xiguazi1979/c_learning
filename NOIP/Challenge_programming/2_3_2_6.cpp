#include <queue>
#include <cstdio>
#include <memory.h>

using namespace std;

const int MAX_N = 3;
const int MAX_K = 17;
int a[] = {3, 5, 8};
int m[] = {3, 2, 3};
int K = MAX_K;
int n = MAX_N;

bool dp[MAX_K + 1]; // use 0, 1, ... ith to get value j, how many ith thing can be left at most

void solve()
{
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= MAX_K; j++) {
            if ( dp[j] >= 0) { // here means dp[j] for 0, 1, ... (i-1)th
                dp[j] = m[i];
            }
            else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            }
            else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }

    if (dp[K] >= 0) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}

int main()
{
    solve();
    return 0;
}