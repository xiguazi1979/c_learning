#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if (n / 10000 != 0){
        printf("%d\n", 5);
    }
    else if (n / 1000 != 0){
        printf("%d\n", 4);
    }
    else if (n / 100 != 0){
        printf("%d\n", 3);
    }
    else if (n / 10 != 0){
        printf("%d\n", 2);
    }
    else {
        printf("%d\n", 1);
    }
    int a = n / 10000;
    int b = (n - 10000*(n / 10000)) / 1000;
    int c = (n - (a * 10 + b)*1000) / 100;
    int d = n / 10;
    int e = n / 1;
    printf("%d %d %d %d %d\n", a ,b, c, d, e);
    printf("%d %d %d %d %d\n", e, d, c, b, a);
    return 0;
}