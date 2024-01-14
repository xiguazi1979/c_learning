#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    scanf("%d%d%d", &a, &b, &c);
    if(a > b){
        d = a;
    }
    else{
        d = b;
    }
    if(d < c){
        d = c;
    }
    printf("%d", d);

    return 0;
}