#include <bits/stdc++.h>
using namespace std;
int n, m, p;
long long a;
int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

int main()
{
	int j;
	scanf("%d%d", &n, &m);
	a = m * n;
	for (int i = n; i <= m; i++) {
		
		if (a % i == 0) {
			j = a / i;
			if(gcd(max(i, j), min(i, j)) == n) {
				//printf("%d %d\n", i, j);
				p++;
			}			
		}

	}
	printf("%d", p);
	return 0;
}
