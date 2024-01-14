#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4;
const int MAX_W = 5;
int n = MAX_N;
int W = MAX_W;
int w[MAX_N] = {2, 1, 3, 2};
int v[MAX_N] = {3, 2, 4, 2};
int dp[MAX_W + 1];

void solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= 0; j--) {
            if (j - w[i] >= 0) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    printf("The result is %d\n", dp[W]);
}

int main()
{
    solve();
    return 0;
}