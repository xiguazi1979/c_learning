#include <cstdio>
#include <algorithm>

using namespace std;

int n = 99;
int m = 100;
int M = 10000;
#define MAX_N 99
#define MAX_M 100
int dp[MAX_N + 1][MAX_M + 1];

void solve()
{
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >=  0) {
                dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M;
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[m][n]);
}

int main()
{
    solve();
    return 0;
}