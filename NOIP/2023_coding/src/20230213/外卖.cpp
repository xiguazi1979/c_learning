#include <bits/stdc++.h>
using namespace std;
int a[5];
int p = 100000001;
int q = -100000001;
int main()
{
	freopen("take_out.in", "r", stdin);
	freopen("take_out.out", "w", stdout);
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= 4; i++) {
		if (p > a[i]) {
			p = a[i];
		}
		if (q < a[i]) {
			q = a[i];
		}
	}
	int x = abs(p - q);
	int y = abs(a[1] - p);
	int z = abs(a[1] - q);
	long long int ans = min(y, z) + x;
	printf("%lld", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
