#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0) {
        printf("the gcd is %d", x);
        return x;
    }
    gcd (y, x % y);
    return -1;
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    gcd(x, y);
    return 0;
}