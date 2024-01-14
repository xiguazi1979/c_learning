#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
void printfexercise()
{
	int a[5];
	int *pa = a;
	for (int i = 0; i < 5; i++) {
		scanf("%d", pa + i);
		
	}
	for (int i = 0; i < 5; i++) {
		printf("a[%d] = %d\n", i, pa[i]);
	}
	return;
}
void moveptr()
{
	int n;
	int *a;
	scanf("%d", &n);
	a = new int[n + 1];
	for (int i = 1; i <=n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <=n; i++) {
		a[i] += a[i-1];
	} 
	for (int i = 1; i <= n; i++) {
		printf("%d", a[i]);
	}
	return;
}
#define LP 100001
int n, m, k;
int x[LP], y[LP], d[LP];
int c[LP]; //每列数据个数 
int *a[LP];


int main()
{
	scanf("%d%d%d", &m, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &x[i], &y[i], &d[i]);
		c[y[i]]++; //统计c数组每列数据个数
		 
	}
	for (int i = 1; i <= m; i++) {
		a[i] = new int[c[i]]; //第i列 
	}
	for (int i = 1; i <= k; i++) {
		*a[y[i]] = d[i];
		a[y[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		a[i] -= c[i];//指针回到每列的前面
		for (int j = 1; j <= c[i]; j++, a[i]++) {
			printf("%d ", *a[i]);
		} 
	}
	return 0;
}





