#include <cstdio>
#include <algorithm>

using namespace std;

int n = 5;
#define MAX_N 5
int a[MAX_N] = {4, 2, 3, 1, 5};
int dp[MAX_N];

void solve()
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(dp[i], res);
    }
    printf("%d", res);
}

int main()
{
    solve();
    return 0;
}