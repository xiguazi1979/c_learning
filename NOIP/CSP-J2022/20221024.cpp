#include <bits/stdc++.h>
using namespace std;

int P[50], Q[50];
int p, m, n, t;
int x0;
int y;

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
	//freopen("timu1.in", "r", stdin);
	//freopen("timu1.out", "w", stdout);
	scanf("%d%d", &x0, &y);
	if(y < x0) {
		printf("%d", 0);
		return 0;
	}
	t = y / x0;
	for (int i = 1; i <= t; i++) {
		if(t % i == 0) {
			m = i;
			n = t / i;
			if (m == n) {
				if (gcd(m, n) == 1) {
					P[p] = m;
					Q[p] = n;
					p++;
				}
			}
			else {
				if (gcd(max(m, n), min(m, n)) == 1) {
					P[p] = m;
					Q[p] = n;
					p++;
				}
			}		
		}
	}
	printf("%d", p);
	/*for (int i = 0; i < p; i++) {
		printf("%d%d", P[i], Q[i]);
	}*/
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
