#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T = 0;
int N = 0;
uint8_t *A = NULL; //A[0 - (N-1)][0 - (N-1)]
int *dp = NULL; //dp[0 - (N-1)][0 - (N-1)]
int n = 0; // number of people
int m = 0; // number of counts
void dumpdp()
{
    return;
    printf("dumpDP:");
    for (int i = 0; i < N; i++) {
        printf("\n");
        for (int j = 0; j < N; j++) {
            printf("%5d", dp[N*i + j]);
        }
    }
    printf("\n");
}
void dumpA()
{
    return;
    printf("dumpA:");
    for (int i = 0; i < N; i++) {
        printf("\n");
        for (int j = 0; j < N; j++) {
            printf("%5d", A[N*i + j]);
        }
    }
    printf("\n");
}

void solve(void)
{
#if 0
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
#endif
    dp[0] = A[0];
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j <= i + 1; j++) {
            if (j == 0) {
                dp[(i + 1) * N] = dp[i * N] + A[(i + 1) * N];
            }
            else if (j == (i + 1)) {
                dp[(i+1)*N+j] = dp[i*N+j-1] + A[(i+1)*N+j];
            }
            else {
                dp[(i+1)*N+j] = max(dp[i*N+j-1],dp[i*N+j])+A[(i+1)*N+j];
            }
            dumpdp();
        }
    }
    int ans = 0;
    for (int i = (N-1) * N;i < (N) * N; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &T);
    for (int x = 0; x < T; x++) {
        scanf("%d", &N);
        A = (uint8_t *)malloc(sizeof(uint8_t) * N * N);
        memset(A, 0, sizeof(uint8_t) * N * N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                scanf("%d", &A[i*N + j]);
                dumpA();
            }
        }
        dp = (int *)malloc(sizeof(int) * N * N);
        memset(dp, 0, sizeof(int) * N * N);
        dumpdp();

        solve();
        
        free(A);
        free(dp);
    }
    return 0;
}