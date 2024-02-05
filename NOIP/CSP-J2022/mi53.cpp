#include <cstdio>
using namespace std;

int a[30] = {1,2,4,7};
int n = 4;
int  k = 13;
bool dfs(int i, int sum){
    if(i == n){
        return sum == k;
    }
    if (dfs(i + 1, sum)){
        return true;
    }
    if (dfs(i + 1, sum + a[i])){
        printf("%d ", a[i]);
        return true;
    }
    else{
        return false;
    }
}
void solve(){
    if (dfs(0, 0)){
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}
int main(){
    solve();
    return 0;
}
