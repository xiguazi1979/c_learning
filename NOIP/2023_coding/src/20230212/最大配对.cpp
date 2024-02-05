#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
int A[MAX_N], B[MAX_N];
int n;
int main()
{
	long long int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}
	sort(A, A + n);
	sort(B, B + n, greater<int>());
	for (int i = 0; i < n; i++) {
		ans += abs(A[i] - B[i]);
	}
	printf("%lld", ans);
	return 0;
}
