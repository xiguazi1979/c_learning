#include <stdio.h>

int main(void)
{
    uint32_t x, y;
    scanf("%ld", &x);
    if (x < 1) {
        y = x;
    }
    else if(1 <= x && x < 10) {
        y = 2 * x - 1;
    }
    else {
        y = 3 * x - 11;
    }
    printf("%d", y);

    return 0;
}