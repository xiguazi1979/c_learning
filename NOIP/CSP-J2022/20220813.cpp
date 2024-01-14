#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 3;
const int W = 7;

int w[MAX_N] = {3, 4, 2};
int v[MAX_N] = {4, 5, 3};

int dp[MAX_N + 1][MAX_N + 1];

void solve()
{
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            }
            else{
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[MAX_N][W]);
}
int main()
{
    solve();
    return 0;
}