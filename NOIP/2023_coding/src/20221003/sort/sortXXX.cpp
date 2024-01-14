#include <bits/stdc++.h>
using namespace std;
int n, Q, k, x, v, loc, m;
int a[8000];
int b[8000];
int c[200000];

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
void pop_sort(int start, int end)
{
	if (start >= end - 1) {
		return;
	}
	for (int i = start; i < end - 1; i++) {
		if (b[i] > b[i + 1]) {
			swap(&b[i], &b[i + 1]);
		}
	}
}

void down_sort(int start, int end)
{
	if (start >= end - 1) {
		return;
	}
	for (int i = end - 1; i > start; i--) {
		if (b[i] < b[i - 1]) {
			swap(&b[i], &b[i - 1]);
		}
	}
}

int binary_search(int l, int r, int x) {
	int R = r + 1;
	int mid = 0;
	while (R - l >= 1) {
		mid = (l + R) / 2;
		if (b[mid] == x) {
			return mid;
		}
		else if (b[mid] < x) {
			l = mid + 1;
		}
		else {
			R = mid;
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
	sort(b, b + n);

	for (int i = 0; i < Q; i++) {
		scanf("%d", &k);
		if (k == 1) {
			scanf("%d%d", &x, &v);
			a[x - 1] = v;
			for (int t = 0; t < n; t++) {
				b[t] = a[t];
			}
//			sort(b, b + n);
#if 1
			down_sort(0, x);
			if (x < n) {
				pop_sort(x - 1, n);
			}
#endif
		}
		else {
			scanf("%d", &x);
			int val = a[x - 1];
			loc = 0;
			for (int j = 0; j < x - 1; j++) {				
				if (a[j] == val) {
					loc++;
				}				
			}
			m = binary_search(0, n - 1, val);
			for (int t = 0; t < n; t++) {
				if (m == 0) {
					break;
				}
				if (b[m - 1] == val) {
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
