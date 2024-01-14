#include <cstdio>
float F;
int main()
{
    float C = 0.0;
    float var = 0.0;
    scanf("%f", &F);
    C = 5 * (F - 32) / 9;
    printf("c=%.2f", C);
    return 0;
}