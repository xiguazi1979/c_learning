#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int V[6] = {1 ,5, 10, 50, 100, 500};
int C[6] = {3, 2, 1, 3, 0, 2};
int total = 620;
void solve()
{
    int answer = 0;
    for(int i = 5; i >= 0; i--){
        int t = min(total / V[i], C[i]);
        total -= V[i] * t;        
        answer = answer + t;
        if(total == 0){
            break;
        }
    }
    printf("\nAnswer is: %d.\n", answer);
}


int main()
{
    solve();
    return 0; 
    
}
