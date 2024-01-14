#include <bits/stdc++.h>

using namespace std;
int n, L, R;
#define INF 5000000000

int main()
{
	//freopen("candy.in", "r", stdin);
	//freopen("candy.out", "w", stdout);
	scanf("%d%d%d", &n, &L, &R);
	for (int i = 1; i <= INF; i++) {
		if (n * i > L) {
			if (n * i <= R) {
				printf("%d", n - 1);
				break;
			}

			else {
				printf("%d", R - n * (i - 1));
				break;
			}
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
