#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
char a[9];

int main()
{
	int ans = 0;
	scanf("%s", &a[0]);
	for (int i = 0; i < 8; i++) {
		if (a[i] == '1'){
			ans += 1;
		}
	}
	printf("%d", ans);
	
	return 0;
}


