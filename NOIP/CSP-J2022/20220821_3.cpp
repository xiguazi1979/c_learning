#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int *dp = NULL; //dp[0-m][0-(n-1)]
int n = 0; // number of people
int m = 0; // number of counts
void dumpdp()
{
    return;
    printf("dumpDP:");
    for (int i = 0; i <= m; i++) {
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("%5d", dp[n*i + j]);
        }
    }
    printf("\n");
}
void solve(int n, int m)
{
// dp[i][j]: dp[n*i + j]
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            dumpdp();
            if (j == 0) {
                dp[n*i] = dp[n*(i-1)+1] + dp[n*(i-1)+(n-1)];
                dumpdp();
            }
            else if (j == n - 1) {
                dp[n*i+(n-1)] = dp[n*(i-1)] + dp[n*(i-1)+(n-2)];
                dumpdp();
            }
            else{
                dp[n*i+j] = dp[n*(i-1)+(j+1)] + dp[n*(i-1)+(j-1)];
                dumpdp();
            }
        }


    }
    printf("%d", dp[n*m]);
}

int main()
{
    scanf("%d %d", &n, &m);
    dp = (int *)malloc(sizeof(int) * (m+1) * n);
    memset(dp, 0, sizeof(int) * (m+1) * n);
    dumpdp();
    solve(n, m);
    return 0;
}