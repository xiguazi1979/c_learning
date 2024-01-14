#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int INF = 10000000;
const int MAX_M = 3; // select volumn
const int MAX_N = 3; // kinds of good
const int a[] = {1, 2, 3};
const int M = 10000;
int m = MAX_M, n = MAX_N;

//int dp[MAX_M + 1][MAX_N + 1];   

void solve()
{
    int dp[MAX_M + 1][MAX_N + 1]; //dp[i+1][j]: from 1, ..., ith kind of goods, select j, how many ways
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - 1 >= a[i]) {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]]);
            }
            else {
                dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j];
            }
        }
    }
    printf("\nAnswer is %d.\n", dp[n][m]);
}

int main()
{
    solve();
    return 0;
}