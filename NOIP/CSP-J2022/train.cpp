#include <bits/stdc++.h>
using namespace std;
int a[256], b[256], c[256],lena, lenb, lenc;
char n[256], n1[256], n2[256];

int main()
{
//	freopen("timu1.in", "r", stdin);
//	freopen("timu1.out", "w", stdout);
	scanf("%s%s", &n1, &n2);
	if (strlen(n1) < strlen(n2) || (strlen(n1) == strlen(n2) && strcmp(n1, n2) < 0)) { // strcmp:字符串比较函数，n1 > n2 return 正整数，n1 == n2, return 0,类推 
		strcpy(n, n1);
		strcpy(n1, n2);
		strcpy(n2, n); 
		printf("-");
	}
	lena = strlen(n1), lenb = strlen(n2);
	for (int i = 0; i < lena; i++) {
		a[lena - i] = n1[i] - 48;
	}
	for (int i = 0; i < lenb; i++) {
		b[lenb - i] = n2[i] - 48;
	}
	int i = 1;
	while(i <= lena || i <= lenb) {
		if (a[i] < b[i]) {
			a[i] += 10;
			a[i + 1]--;
		}
		c[i] = a[i] - b[i];
		i++;
	}
	lenc = i;
	while (c[lenc] == 0 && lenc > 1) {
		lenc--;
	}
	for (int i = lenc; i >= 1; i--){
		printf("%d", c[i]);
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;	
} 
