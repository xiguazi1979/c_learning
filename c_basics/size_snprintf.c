#include "stdio.h"
#include "string.h"

int main(void)
{
    char mfg_date[8] = {0};
    char dest[8];
    unsigned int m = 4294967210;
    int xx = m;
    long x = (int)m;
    unsigned long y = 0;
    long z = 0;
    y = (unsigned long)x;
    printf("sizeof long(%d), longlong(%d)\n", sizeof(long), sizeof(long long));
    printf("uint to int is %d\n", xx);
    printf("x is %#llX\n", x);
    printf("y(ulong) is %llu\n", y);
    z = y;
    printf("z(y to long) is %lld\n", z);
    for (int i = 0; i < 8; i++) {
            mfg_date[i] = 'A' + i;
    }
    strncpy(dest, mfg_date, sizeof(dest));
    printf("test strncpy for equal length:\n");
    for (int i = 0; i < 8; i++) {
        printf("%d:%c.", dest[i]);
    }
    return 0;
}