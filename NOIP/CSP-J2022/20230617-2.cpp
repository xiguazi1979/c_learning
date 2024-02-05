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
		x  = find(par[x]);
		return x;
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
	int n, m;
	int x, y, z;
	scanf("%d%d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d",&z, &x, &y);
		if (z == 1) {
			unite(x, y);
		}
		if (z == 2) {
			if (same(x, y)) {
				printf("Y\n");
			}
			else {
				printf("N\n"); 
			}			
		}
	}	
#if 0
/*

	for (int i = 0; i < p; i++) {
		scanf("%d%d", &x, &y);

	}
*/
#endif	
	return 0;
}
