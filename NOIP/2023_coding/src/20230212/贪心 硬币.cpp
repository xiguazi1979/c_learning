#include <bits/stdc++.h>
using namespace std;

const int V[6] = {1,5,10,50,100,500};
int C[6] = {3, 2, 1, 3, 0, 2};
int total = 620;
void solve()
{
	int ans = 0;
	sort(); 
	for(int i = 5; i >= 0; i--) {
		int t = min(total / V[i], C[i]);
		ans += t;
		total = total - t * V[i];
		printf("V[%d]: %d.", V[i], t);
	}
	printf("\nans is:%d.", ans);
}
int main()
{
	solve();
	return 0;
}
