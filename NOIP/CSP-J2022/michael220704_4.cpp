#include <stdio.h>
int main(void)
{

    int x;

    if ((x=1) && (x=2) && (x=3)) {
        printf("x is %d.", x);
    }
    return 0;
}