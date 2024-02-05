#include <cstdio>
using namespace std;

int result[55] = {0,1,2,3,4};
int solve(int n)
{
    int ans;
    if (result[n] > 0) {
        return result[n];
    }   

    
    ans = solve(n - 1) + solve(n - 3);
    result[n] = ans ;
    return ans;
    
}

int main()
{
    int ans;
    while(EOF != scanf("%d", &ans)){
        if (ans == 0){
            return 0;
        }
        printf("%d\n", solve(ans));
    }
    return 0;    
}