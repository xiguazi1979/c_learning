#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4;
const int MAX_M = 4;

char s[MAX_N + 1] = "abcd";
char t[MAX_M + 1] = "becd";

int dp[MAX_N + 1][MAX_M + 1];   //s0...s(i-1) and t0...t(j-1) LCS

void solve()
{
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_M; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    printf("\nAnswer is %d.\n", dp[MAX_N][MAX_M]);
}

int main()
{
    solve();
    return 0;
}