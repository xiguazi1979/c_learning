#include <bits/stdc++.h>
using namespace std;
int N, X;
int a[100];
int ans[100];
int final;

int main()
{
	scanf("%d%d", &X, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + N);
	if (a[1] != 1) {
		printf("-1");
	}
	int sum = 0;
	while (sum < X){
		for (int i = N; i >= 1; i--) {
			if (a[i] <= (sum + 1)) {
				ans[i]++;
				sum += a[i];
				break;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		final += ans[i];
	}
	printf("%d", final);
	return 0;	
}
