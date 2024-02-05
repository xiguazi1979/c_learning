#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1001
int n;
int a[MAX_N], b[MAX_N], c[MAX_N];
int ans[4];
int gcd (int x, int y) {
	
	if (x == 1 || y == 1) {
		return 1;
	}
	if (x == y) {
		return x;
	}
	else if (x - y < y) {
		return gcd(y, x-y);
	}
	else {
		return gcd(x-y, y);
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			ans[1] = a[i];
			ans[2] = b[i];
			ans[3] = c[i];
			continue; 
		}
		else if (c[i] == ans[3]) {
			ans[1] = ans[1]*b[i] + ans[2]*a[i];
		}
		else {
			int x = ans[1] / ans[2];
			int y = a[i] / b[i];
			if (y > x) {
				ans[3] = c[i];
				ans[1] = ans[2]*a[i] - ans[1]*b[i];
			}
			else if (x > y) {
				ans[1] = ans[1]*b[i] - ans[2]*a[i];
			}
			else if (x == y) {
				if (ans[1]*b[i] - ans[2]*a[i] > 0) {
					ans[1] = ans[1]*b[i] - ans[2]*a[i];
				}
				else {
					ans[3] = c[i];
					ans[1] = ans[2]*a[i] - ans[1]*b[i];
				}
			}
		}
		ans[2] = ans[2] * b[i];
		if (ans[1] % ans[2] == 0) {
			ans[1] /= ans[2];
			ans[2] = 1;
		}
		else {
			int chushu = gcd(ans[1], ans[2]);
			ans[1] /= chushu;
			ans[2] /= chushu;
		}
	}
	if (ans[2] == 1) {
		if (ans[3] == 2){
			printf("-%d", ans[1]);
		}
		else {
			printf("%d", ans[1]);
		}
	}
	else{
		if (ans[3] == 2){
			printf("-%d/%d", ans[1], ans[2]);
		}
		else {
			printf("%d/%d", ans[1], ans[2]);
		}		
	}
	return 0;
}
