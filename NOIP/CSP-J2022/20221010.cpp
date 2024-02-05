#include <bits/stdc++.h>
using namespace std;

int plusandtime()
{
	int a, b, *pa, *pb;
	pa = &a;
	pb = &b;
	a = 10;
	b = 20;
	int s = *pa + *pb;
	int t = *pa * *pb;
	printf("%d %d\n", s, t);
	return 0;
}

int ptrprintf()
{
	int a[101], n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		
	}
	int *p = &a[1];
	for (int i = 1; i <= n; i++) {
		printf("%d ", *p);
		p++;//刚好跳过一个整数空间到达下一个整数 
	}
	return 0;
}
int voidptr()
{
	int a = 10;
	double b = 3.5;
	void *p;
	p = &a;
	printf("%d\n", *(int *)p);
	p = &b;
	printf("%f\n", *(double *)p);
	return 0;
}

int doubleptr()
{
	int a = 10;
	int *p = &a;
	int **pp = &p;
	printf("%d = %d = %d", a, *p, **pp);
	return 0;
}
int main()
{
	//plusandtime();
	//zhizhenprintf();
	voidzhizhen();
	//doublezhizhen();
	return 0;
}












