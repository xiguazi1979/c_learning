#include <bits/stdc++.h>
using namespace std;
long long int v[1001];
long long int dp[1001][1001];
int a, k;
int n;
long long int x[1001];
//long long int y[1001];
int main()
{
	//freopen("interval.in", "r", stdin);
	//freopen("interval.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		long long int m = pow(a, 2);
		v[i] = m - a - k;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i- 1][j] + v[j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		//for (int j = 1; i <= n; j++) {
		//	y[j] = dp[i][j];
		//}
		sort(&dp[i][1], &dp[i][1] + n);
		x[i] = dp[i][n+1];
	}
	sort(x, x + n);
	printf("%lld", x[n]);
	return 0;
	//fclose(stdin);
	//fclose(stdout);
}
