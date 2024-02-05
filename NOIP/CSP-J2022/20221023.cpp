#include <bits/stdc++.h>
using namespace std;

#define MAX_P 8000
typedef struct num {
	int first;
	int second;
	int third;
}num;
int n, p, p5;
num ans[MAX_P];
void Found5()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (2*i + 2*j + k == n) {
					ans[p].first = i;
					ans[p].second = j;
					ans[p].third = k;
					p++;
				}
			}
		}
	}
	p5 = p;//6µÚÒ»Ïî 
}
void Found6()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (2*i + 2*j + 2*k == n) {
					ans[p].first = i;
					ans[p].second = j;
					ans[p].third = k;
					p++;
				}
			}
		}
	}	
}
int main()
{
	//freopen("timu1.in", "r", stdin);
	//freopen("timu1.out", "w", stdout);
	scanf("%d", &n);
	if (n > 54) {
		printf("%d", -1);
		return 0;
	}
	if (n > 45) {
		
		if (n%2 == 1) {
			printf("%d", -1);
			return 0;
		}
		Found6();
	} 
	else {
		Found5();
		if (n % 2 == 0) {
			Found6();
		}
		
	}
	for (int i = 0; i < p5; i++) {
		printf("%d%d%d%d%d\n", ans[i].first, ans[i].second, ans[i].third, ans[i].second, ans[i].first);
	}
	for (int i = p5; i < p; i++) {
		printf("%d%d%d%d%d%d\n", ans[i].first, ans[i].second, ans[i].third, ans[i].third, ans[i].second, ans[i].first);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
