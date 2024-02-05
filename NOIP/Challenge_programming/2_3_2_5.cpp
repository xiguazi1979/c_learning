#include <queue>
#include <cstdio>

using namespace std;

const int MAX_N = 3;
const int MAX_K = 17;
int a[] = {3, 5, 8};
int m[] = {3, 2, 3};
int K = MAX_K;
int n = MAX_N;

bool dp[MAX_N + 1][MAX_K + 1];

void solve()
{
    dp[0][0] = true;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= MAX_K; j++) {
            for (int k = 0; k <= m[i] && k * a[i] <= j; k++) {
                dp[i + 1][j] |= dp[i][j - k * a[i]];
            }
        }
    }

    if (dp[n][K] == true) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}

int main()
{
    solve();
    return 0;
}