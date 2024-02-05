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

int dp[MAX_N + 1][MAX_K + 1];

void solve()
{
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[i][j] >= 0) {
                dp[i + 1][j] = m[i];
            }
            else if (j < a[i] || dp[i + 1][j - a[i]] <= 0)
            {
                dp[i + 1][j] = -1;
            }
            else {
                dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
            }
            
        }
    }

    for (int i = 0; i < n; i++) {
        if (dp[i + 1][K] >= 0) {
            printf("Yes!\n");
        }
    }
}

int main()
{
    solve();
    return 0;
}