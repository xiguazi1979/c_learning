#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100001
int n, w;
int a[MAX_N];

int binary_search(int x, int p) {
	int l = 0;
	int r = p;
	while (r - l >= 1) {
		int i = (l + r) / 2;
		if(a[i] > x && a[i - 1] <= x) {
			return i;
		}
		else if(a[i] > x) {
			l = i + 1;
		}
		else {
			r = i; 
		}
	}
	return (p - 1); 
}

int main()
{
	//freopen("live.in", "r", stdin);
	//freopen("live.out", "w", stdout);
	
	scanf("%d%d", &n, &w);
	for (int p = 1; p <= n; p++) {
		int x = 0;
		scanf("%d", &x);
		if (p == 1) {
			a[0] = x;
			printf("%d ", a[0]);
			continue;
			} 
		a[p - 1] = x;
		sort(a, a + p);
			
/*		for (int i = 0; i < p; i++) {			
			if (a[i] > x) {
				for (int j = p - 2; j >= i; j--) {
					a[j + 1] = a[j];
				}
				a[i] = x;
				break;
			}
			if (i == (p - 1)) {
				a[i] = x;
			}
		}
*/

/*		int i = binary_search(x, p);
		if (i == p - 1) {
			a[i] = x;
		}
		else {
			for (int j = p - 2; j >= i; j--) {
				a[j + 1] = a[j];
			}
			a[i] = x;	
		}
*/		
		int ans = p - max(1, (p * w / 100));
		printf("%d ", a[ans]);
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
