#include <bits/stdc++.h>
using namespace std;
#define DBG 1

int n, m;
int x;
int ans;
int y = 1;
int cur_badoffer = 0;
int borrowed = 0;
int r[1000005], d[1000005], s[1000005], t[1000005], p[1000005];
int a[1000005], b[1000005];

void dbg_print(int  n, int *ptr)
{
#ifdef DBG
	printf("dbg print start:\n");
	for (int i = 1; i <=n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
#endif
}

int get_offernum(int day)
{
	int val = 0;
	for (int i = 1; i <= m; i++) {
		if (s[i] <= day && t[i] >= day) {
			val += d[i];
			if (val > r[day]) {
				return i;
			}
		}		
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
	}
	cur_badoffer = m;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &d[i], &s[i], &t[i]);
	} 
	for (int i = 1; i <= m; i++) {
		p[s[i]] += d[i];
		p[t[i] + 1] -= d[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i-1] + p[i];
	}
	dbg_print(n, a);

	for (int i = 1; i <= n; i++) {
		if (a[i] <= r[i]) {
			continue;
		}
		else {
			x = i;
			int tmp;
			tmp = get_offernum(i);
			if (tmp < cur_badoffer) {
				cur_badoffer = tmp;
			}
		}
	}
	if (x == 0) {
		printf("0");		
	}
	else {
		printf("-1\n%d", cur_badoffer);
	}
	
	return 0;
}
