#include <bits/stdc++.h>
using namespace std;

long long int n, L, R;

int main()
{
	//freopen("candy.in", "r", stdin);
	//freopen("candy.out", "w", stdout);
	scanf("%d%d%d", &n, &L, &R);
	if (R - L > n - 1) {
		printf("%lld", n-1);
	}
	else {
		long long int x = L % n;
		long long int y = R % n;
		if (x > y) {
			printf("%lld", n-1);
		}
		else {
			printf("%lld", y);
		}
	}
	return 0;
	//fclose(stdin);
	//fclose(stdout);
} 
