#include <stdio.h>

int main(void)
{
    int a = 2;
    int i, j, k, x, y, n;
    unsigned long long int Sn = 0L;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        x = 0;
        for (j = 0; j < i; j++) {
            if (j == 0) {
                y = 1;
            }
            else {
                y = 1;
                for (k = 0; k < j; k++) {
                        y *= 10;
                }
            }
            x += a * y;
        }
        Sn += x;
    }

    printf("%d", Sn);

    return 0;
}