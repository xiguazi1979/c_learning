#include <cstdio>
float x;
float y;
int main()
{
    scanf("%f", &x);
    if (x < 1){
        y = x;
    }
    else if (1 <= x && x < 10){
        y = 2 * x - 1;
    }
    else if (x >= 10) {
        y = 3 * x - 11;
    }
    printf("%d\n", (int)y);
    printf("%f\n", y);
    return 0;
}