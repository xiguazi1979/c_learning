#include <cstdio>
using namespace std;
int min(int x,int y)
{
    if(x >= y){
        return y;
    }
    return x;
}
int main()
{
    int m;
    int n;
    int yin;
    int bei;
    scanf("%d%d", &m,&n);
    int var = min(m,n);
    for (int i = var; i > 0; i--){
        if(m % i == 0 && n % i == 0){
            yin = i;
            m/=i;
            n/=i;
            bei = yin*m*n;
            break;
        }

    }
    printf("%d\n%d",yin,bei);
    return 0;
}
