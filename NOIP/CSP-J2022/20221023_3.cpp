#include <bits/stdc++.h>
using namespace std;

int n, p;
char x;
bool quit = false;
typedef struct record{
	char str[1001];
}record;
record a[1000];
int main()
{
	//freopen("timu1.in", "r", stdin);
	//freopen("timu1.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0; i < 1000 && !quit; i++) {
		for (int j = 0; j < 1000; j++) {
			
			scanf("%c", &x);
			if (x == '\n' && j == 0) {
				quit = true;
				break;
			}
			if (x != '\n') {
				a[i].str[j] = x;
			}
			else {
				a[i].str[j] = '\n';
				break;
			}
		}
		p++;
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < 1000; j++) {
			if (a[i].str[j] != '\n') {
				printf("%c", a[i].str[j]);
			}
			else {
				printf("\n");
				break;
			}
		}
		printf("\n");
	}
	for (int i = n; i < p; i++) {
		int j = 0;
		//printf("\n");
		while(a[i].str[j] != '\n') {
			if (a[i].str[j] == 0) {
				break;
			}
			while(a[i].str[j] != ' ' && a[i].str[j] != '\n') {
				printf("%c", a[i].str[j]);
				j++;
			}
			printf("\n");
			if (a[i].str[j] == '\n') {
				break;
			}
			printf("\n");
			j++;
		}
		printf("\n");
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
