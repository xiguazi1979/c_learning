#include <cstdio>
int result[55] = {0,1,2,3,4};
void solve(int n)
{
    if (n<5) {
        return;
    }
    for (int i = 5; i<=n; i++) {
        result[i] = result[i-1] + result[i-3];
    }
    return;
}
int main()
{
    int n = 0;
    solve(54);
    while(EOF != scanf("%d", &n)){
        if (n == 0){
            return 0;
        }
        if (n > 54){
            return 0;
        }
        printf("%d\n", result[n]);
    }
    return 0;
}