#include <bits/stdc++.h>
using namespace std;
char a[100];
char b[1000];
void GetReal() 
{
	printf("please input a number:\n");
	scanf("%s", a);
}
void GetString()
{
	printf("please input a string:\n");
	scanf("%s", b);
}
int main()
{
	GetReal();
	GetString();
	printf("%s\n", a);
	printf("%s", b);
	return 0;
}
