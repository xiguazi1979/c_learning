#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4;
const int MAX_W = 5;
int n = MAX_N;
int W = MAX_W;
int w[MAX_N] = {2, 1, 3, 2};
int v[MAX_N] = {3, 2, 4, 2};
int dp[MAX_N][MAX_W];

void solve()
{
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i - 1]);
            }
        }
    }
    printf("The result is %d\n", dp[n][W]);
}

int main()
{
    solve();
    return 0;
}