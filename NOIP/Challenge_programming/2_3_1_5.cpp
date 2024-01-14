#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4;
const int MAX_W = 5;
int n = MAX_N;
int W = MAX_W;
int w[MAX_N] = {2, 1, 3, 2};
int v[MAX_N] = {3, 2, 4, 2};

int dp[MAX_N + 1][MAX_W + 1];   //dp[i+1][j]: 0, 1, 2, ..., i-th, select total weight <= j


void solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
#if 1
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + w[i] <= W) {
                dp[i + 1][j + w[i]] = max(dp[i][j + w[i]], dp[i][j] + v[i]);
            }
#endif
#if 0
            if (j + w[i] <= W) {
                dp[i + 1][j] = dp[i][j];
                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i + 1]], dp[i][j] + v[i]);
            }
            else {
                dp[i + 1][j] = dp[i][j];
            }
#endif
        }
    }

    printf("\nresult is %d\n", dp[n][W]);
}

int main()
{
    solve();
    return 0;
}