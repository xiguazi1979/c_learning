#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 3;
int n = 3;
int kk[MAX_N * MAX_N];



extern void solve2();
bool binary_search(int x)
{
    int k[MAX_N] = {3, 1, 5};
    int left = 0;
    int right = n;

    sort (k, k + n);
    while (right - 1 >= left){
        int i = (right + left) / 2;
        if (k[i] == x){
            return true;
        }
        else if (x > i)
        {
            left = i + 1;
        }
        else 
        {
            right = i - 1;
        }
    }
    return false;
}

bool binary_search2(int x)
{
    int left = 0;
    int right = n;

    while (right - 1 >= left){
        int i = (right + left) / 2;
        if (kk[i] == x){
            return true;
        }
        else if (x > kk[i])
        {
            left = i + 1;
        }
        else 
        {
            right = i - 1;
        }
    }
    return false;
}

void solve2()
{
    int k[MAX_N] = {3, 1, 5};
    int m = 10;
    int a,b,c,d;
    int counter = 0;
    sort(k, k + n);
    bool f = false;
    for (a = 0; a < n; a++){
        for (b = 0; b < n; b++){
            for (c = 0; c < n; c++){
                if (binary_search(m - k[a] - k[b] - k[c])){
                    d = m - k[a] - k[b] - k[c];
                    f = true;
                    printf("its double :%d %d %d %d", k[a], k[b], k[c], d);
                    counter++;
                }
            }
        }
    }

    if (!f){
        printf("it's imposible!");
    }
    /**else {
        printf("The amount of the answer is %d", counter);
    }
    */
}

void solve3()
{
    int a, b, c, d;
    int m = 10;
    int f = false;
    int k[MAX_N] = {3, 1, 5};
    for (c = 0; c < n; c++){
        for (d = 0; d < n; d++){
            kk[c * n + d] = k[c] + k[d];
        }
    }
    sort(kk, kk + n * n);

    for (a = 0; a < n; a++){
        for (b = 0; b < n; b++){
            if (binary_search2(m - k[a] - k[b])){
                f = true;
                printf("the answer are%d %d %d %d", k[a], k[b], k[c], k[d]);
            }
        }
    }
    if (!f){
        printf("It's impossible!");
    }
}

int main()
{
    solve3();
    return 0;
}