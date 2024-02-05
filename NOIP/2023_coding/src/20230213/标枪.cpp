#include <bits/stdc++.h>
using namespace std;

int n, A, B, C;
long long ans;
#define INF 1000000007
long long int a[601];
long long int x[601];

long long int findbefore(int i)
{
	int tmp = 0;
	for (int j = 1; j < i; j++) {
		if(tmp < x[j] && x[j] < x[i]) {
			tmp = x[j];
		}
	}
	return tmp;
}

long long int findbehind(int i)
{
	int tmp = INF;
	for (int j = 1; j < i; j++) {
		if(tmp > x[j] && x[j] > x[i]) {
			tmp = x[j];
		}
	}
	if (tmp == INF) {
		return 0;
	} 
	return tmp;
}

int main()
{
	//freopen("javelin.in", "r", stdin);
	//freopen("javelin.out", "w", stdout);
	scanf("%d", &n); 
	scanf("%d%d%d%d", &A, &B, &C, &a[1]);
	for (int i = 2; i <= n; i++) {
		long long int r = pow(a[i-1], 2);
		r = r % 1000000007;
		r = r * A;
		r = r % 1000000007;
		long long int s = a[i - 1] * B;
		s = s % 1000000007;
		long long int t = r + s;
		t = t % 1000000007;
		a[i] = (t + C) % 1000000007;
	}
	for (int i = 1; i <= n; i++) {
		x[i] = a[i] % n;
		x[i] = x[i] + 1;
	}
	for (int i = 2; i <= n; i++) {
		ans += findbefore(i);
		ans = ans % 1000000007;
		ans += findbehind(i);
		ans = ans % 1000000007;
	}
	printf("%lld", ans);
	return 0;
	//fclose(stdin);
	//fclose(stdout);
}
