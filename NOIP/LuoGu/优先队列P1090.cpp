#include <bits/stdc++.h>
using namespace std; 

int n;
int x, y, ans;
int a[10005];
priority_queue<int> q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		q.push(-a[i]);
	}
	for (int i = 1; i < n; i++) {
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	printf("%d", -ans);
	return 0;
}
