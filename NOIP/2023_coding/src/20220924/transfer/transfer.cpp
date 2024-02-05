#include <bits/stdc++.h> 
#include <stdio.h>

using namespace std;

#define INF 0xFFFFFFFF
#define MAX_NUM 100000
int type[MAX_NUM];
int p[MAX_NUM];
int t[MAX_NUM];
int valid[MAX_NUM];

int search(int i)
{
	for (int j = max(0, i - 46); j < i; j++) {
		if ((t[i] - t[j]) <= 45) {
			if (valid[j] == 1) {
				if (p[j] >= p[i]) {
					valid[j] = 0;
					return j;
				}
			}
		}
	}
	return INF;	
}
int main()
{
	//freopen("transfer.in", "r", stdin);
	//freopen("transfer.out", "w", stdout);
	int n;
	int ans = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &type[i], &p[i], &t[i]);
	}
	for (int i = 0; i < n; i++) {
		if (type[i] == 0) {
			ans += p[i];
			valid[i] = 1;
		}
		if (type[i] == 1) {
			int m = search(i);
			if (m == INF) {
				ans += p[i];
			}
		}
	}
	printf("%d", ans);
	
	//fclose(stdin);
	//fclose(stdout);
 	return 0;
 } 
