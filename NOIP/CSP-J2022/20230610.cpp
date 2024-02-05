#include <bits/stdc++.h>
using namespace std;
queue <int> q;
int a[10001];
int t;
int main()
{
	int n, k, r;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	for (int i = 1; i <= n * k; i++) {
		if (i % k != 0) {
			r = q.front();
			q.pop();
			q.push(r);
		}
		if (i % k == 0) {
			a[t++] = q.front();
			q.pop();
		}
		if (t == n) {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
	}
	
	return 0;
}
	

 
 
 
 
 
 
