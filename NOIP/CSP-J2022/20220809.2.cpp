#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4;
const int MAX_W = 5;
int n = MAX_N;
int W = MAX_W;
int w[MAX_N] = {2, 1, 3, 2};
int v[MAX_N] = {3, 2, 4, 2};

int dp[MAX_N + 1][MAX_W + 1];

void solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + w[i] <= W) {
                dp[i + 1][j + w[i]] = max(dp[i][j + w[i]], dp[i][j] + v[i]);
            }
        }
    }
    printf("The answer is %d", dp[n][W]);
}

int main()
{
    solve();
    return 0;
}