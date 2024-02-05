#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0) {
        //printf("the gcd is %d", x);
        return x;
    }
    gcd(y, x % y);
    return 0;
}

int extgcd(int a, int b, int* x, int* y){

    int d = a;
    int xx, yy;
    if(b != 0) {
        d = extgcd(b, a%b, &xx, &yy);
        *x = yy;
        *y = xx - (a/b) * yy;
        //d = extgcd(b, a % b, y, y -= (a / b) * x);
        
    }
    else {
        *x = 1; 
        *y = 0;
    }
    //printf("gcd is %d", d);
    return d;
}

int main() 
{
    int a, b, x, y, d;
    scanf("%d%d", &a, &b);
    d = extgcd(a, b, &x, &y);
    printf("gcd is %d\n", d);
    printf("x=%d, y=%d", x, y);
}