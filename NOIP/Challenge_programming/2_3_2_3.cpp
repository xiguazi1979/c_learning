#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

const int INF = 10000000;
const int MAX_N = 4;
const int W = 5;
const int MAX_V = 4;

int w[MAX_N] = {2, 1, 3, 2};
int v[MAX_N] = {3, 2, 4, 2};

int dp[MAX_N + 1][MAX_N * MAX_V + 1];   

void solve()
{
    //int dp[MAX_N + 1][MAX_N * MAX_V + 1];
    int answer_N = 0, answer_V = 0;
    //memset(dp[0], 0, MAX_N * MAX_V + 1);
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= MAX_N * MAX_V; j++) {
            if (j < v[i]) {
                dp[(i + 1)][j] = dp[i][j];
            }
            else {
                dp[(i + 1)][j] = min(dp[i][j], dp[(i)][j - v[i]] + w[i]);
            }
        }
    }

    for (int i = 0; i <= MAX_N; i++) {
        for (int j = MAX_N * MAX_V; j >= 0; j--) {
            if (dp[i][j] != INF) {
                if (dp[i][j] <= W) {
                    if (answer_V < j) {
                        answer_V = j;
                        answer_N = i;
                    }
                }
            }
        }
    }
    printf("\nAnswer is %d[%d].\n", answer_V, answer_N);
}

int main()
{
    solve();
    return 0;
}