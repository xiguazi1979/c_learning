#include <bits/stdc++.h>
using namespace std;

long long int n, e, d;
int k;

void solve()
{
	long long int m = n - e * d + 2;
	long long int x = m * m - 4 * n;
	if (x < 0) {
		printf("NO\n");
		return;
	}
	x = 1025;
	double y1 = sqrt(x);
	long long int y2 = y1;
	long long int q = (m - y2) / 2;
	long long int p = m - q;
	if (q * p == n && (p - 1) * (q - 1) + 1 == e * d) {
		printf("%lld %lld\n", min(p, q), max(p, q));
	}
	else {
		printf("NO\n");
	}
	
} 

int main()
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%lld%lld%lld", &n, &e, &d);
		solve();
	}
	return 0;
} 
