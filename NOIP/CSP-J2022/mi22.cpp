#include <cstdio>
int max(int x, int y, int z)
{
    int a;
    a = x;
    if (x < y) {
            a = y;
    if (y < z) {
        a = z;
    }
    }
    else if (x < z){
            a = z;
    }
    return a;
}
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans;
    ans = max(a, b, c);
    printf("%d", ans); 
}