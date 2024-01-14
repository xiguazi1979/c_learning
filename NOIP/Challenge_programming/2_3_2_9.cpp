#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int INF = 10000000;
const int MAX_M = 3;
const int MAX_N = 4;
const int M = 10000;
int m = MAX_M, n = MAX_N;

//int dp[MAX_M + 1][MAX_N + 1];   

void solve()
{
    int dp[MAX_M + 1][MAX_N + 1]; 
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // ??why 1

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >= 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("\nAnswer is %d.\n", dp[m][n]);
}

int main()
{
    solve();
    return 0;
}