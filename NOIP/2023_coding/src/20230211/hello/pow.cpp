#include <bits/stdc++.h>
using namespace std;
long long int a, b;
long long int ans = 1;
int main()
{
	//
	scanf("%lld%lld", &a, &b);
	if (a == 1) {
		printf("1");
		return 0;
	}
	if (a > 1000000000) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < b; i++) {
		ans *= a;
		if (ans > 1000000000) {
			printf("-1");
			return 0;
		}
	}
	printf("%lld", ans);
	return 0;
	
}
