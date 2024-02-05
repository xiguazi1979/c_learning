#include <bits/stdc++.h>
using namespace std;
int n;
#define INF 24
int ans[24];

int main()
{
	//freopen("power.in", "r", stdin);
	//freopen("power.out", "w", stdout);
	
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("%d", -1);
		return 0;
		
	}
	else{
		int p = 0;
		for (int j = 0; j < INF; j++) {
			for (int i = 2; i <= n; i *= 2) {
				if (n / i == 1) {
					ans[p] = i;
					p++;
					n -= i;
				}
			}
			if (n == 0) {
				break;
			}	
		}
		for (int i = 0; i < p; i++) {
			printf("%d ", ans[i]);
		}
			
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
