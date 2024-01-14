#include <bits/stdc++.h>
using namespace std;
int n, f, m, x;
int main()
{
	int tmp; 
	scanf("%d%d%d", &n, &m, &f);
	for (x = 1; x < 1024; x++) {
		tmp = 1;
		if (x % 2 == 0) {
			continue;
		}
		for (int i = 1; i <= n; i++) {
			tmp *= x;
			tmp = tmp % m;
		}
		if (tmp == f) {
			printf("%d", x);
			break;
		}
	}
	if (tmp != f) {
		printf("-1");
	}
	return 0;
} 
