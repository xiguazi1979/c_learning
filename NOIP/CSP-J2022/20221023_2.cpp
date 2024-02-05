#include <bits/stdc++.h>
using namespace std;
typedef struct infor{
	char name[21];
	char num[21];
	char sex; 
}infor;
int n, m;
infor a[1000];
char find1[21], find2[21];

int Find(char find[21]) 
{
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].name, find) == 0 || strcmp(a[i].num, find) == 0) {
			return i;
		}
	}
	return -1;
}
int main() 
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s %c", a[i].name, a[i].num, &a[i].sex);
	}	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s%s", find1, find2);
		int x = Find(find1);
		int y = Find(find2);
		if (a[x].sex != a[y].sex) {
			printf("%c\n", 'Y');
		}
		else {
			printf("%c\n", 'N');
		}
		for (int i = 0; i < 21; i++) {
			find1[i] = 0;
			find2[i] = 0;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
