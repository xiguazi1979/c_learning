#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10086

int par[MAX_N];
int rank[MAX_N];

void init(int n)
{
	for (int i = 0; i < n; i++){
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x){
		return x;
	}
	else {
		return find(par[x]);
	}
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank[x] = rank[y]) {
			rank[x]++;
		}
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	int n, m, p;
	int x, y;
	scanf("%d%d%d", &n, &m, &p);
	init(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		unite(x, y);
	}
	for (int i = 0; i < p; i++) {
		scanf("%d%d", &x, &y);
		if (same(x, y)) {
			printf("Yes\n");
		}
		else {
			printf("No\n"); 
		}
	}
	return 0;
}
