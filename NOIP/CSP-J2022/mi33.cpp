#include <cstdio>
using namespace std;

long long int jiecheng(int n)
{
    long long int result = 1;
    for (int i = 1; i <= n; i++){
        result = result * i;
    }
    return result;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long int result = 0;
    for (int i = 1; i <= n; i++){
        result = result + jiecheng(i);
    }
    printf("%lld", result);
    return 0;
}