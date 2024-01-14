#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char a[100];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        gets(a);
        puts(a);
        printf("\n");
    }
    while(scanf("%s",a))
    {
        printf("%s\n",a);
        printf("\n");
    }
    return 0;
}
