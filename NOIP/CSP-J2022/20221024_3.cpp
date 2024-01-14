#include <bits/stdc++.h> 
using namespace std;
int p;
int n, jiangall;
typedef struct infor {
	char name[21];
	int qimo;
	int banji;
	char ganbu;
	char xibu;
	int lunwen;
	int jiang;
}infor;
infor a[101];
void yuanshi(int i)
{
	if(a[i].qimo > 80 && a[i].lunwen >= 1) {
		a[i].jiang += 8000;
	}
}
void wusi(int i)
{
	if(a[i].qimo > 85 && a[i].banji > 80) {
		a[i].jiang += 4000;
	}
}
void chengji(int i)
{
	if(a[i].qimo > 90) {
		a[i].jiang += 2000;
	}
}
void xibujiang(int i)
{
	if(a[i].qimo > 85 && a[i].xibu == 'Y') {
		a[i].jiang += 1000;
	}
}
void banjijiang(int i)
{
	if(a[i].banji > 80 && a[i].ganbu == 'Y') {
		a[i].jiang += 850;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d %c %c%d", &a[i].name, &a[i].qimo, &a[i].banji, &a[i].ganbu, &a[i].xibu, &a[i].lunwen);
	}
	for (int i = 0; i < n; i++) {
		yuanshi(i);
		wusi(i);
		chengji(i);
		xibujiang(i);
		banjijiang(i);
		
	} 
	
	for (int i = 0; i < n; i++) {
		if(a[p].jiang < a[i].jiang) {
			p = i;
		}
		jiangall += a[i].jiang;
	}
	printf("%s\n%d\n%d", a[p].name, a[p].jiang, jiangall);
}
