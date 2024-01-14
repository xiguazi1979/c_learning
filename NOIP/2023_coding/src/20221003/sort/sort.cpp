
#include <bits/stdc++.h>
using namespace std;
int n, Q, k, x, v, loc, m;
int a[8000];
int b[8000];
int c[100000];

int binary_search(int l, int r, int x) {
	while (r - l >= 1) {
		int mid = (l + r) / 2;
		if (b[mid] == x) {
			return mid;
		}
		else if (b[mid] < x) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
			
	}
	return -1;
}

int main()
{
	//freopen("sort.in", "r", stdin);
	//freopen("sort.out", "w", stdout);
	//fclose (stdin);
	//fclose (stdout); 
	scanf("%d%d", &n, &Q);
	int q = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d", &k);
		if (k == 1) {
			scanf("%d%d", &x, &v);
			a[x - 1] = v;
			//b[x - 1] = v;
		}
		else {
			for (int t = 0; t < n; t++) {
				b[t] = a[t];
			}
			scanf("%d", &x);
			sort(b, b + n);
			loc = 0;
			for (int j = 0; j < x - 1; j++) {				
				if (a[j] == a[x - 1]) {
					loc++;
				}
				
			}
			m = binary_search(0, n, a[x - 1]);
			for (int t = 0; t < n; t++) {
				if (b[m - 1] == a[x - 1]) {
					m--;
				}
				else {
					break;
				}
			}
			c[q] = m + loc + 1;
			q++;
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", c[i]);
	}
	return 0;
}
