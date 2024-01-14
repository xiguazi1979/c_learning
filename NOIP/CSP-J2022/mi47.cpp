#include <cstdio>
using namespace std;
#define MAX_N (3 * 100)
//#define MAX_N 10
#define MAX_K 7
int par[MAX_N];
int rank[MAX_N];

void init(int n){
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
    return;
}

int find(int x) {
    if (par[x] == x) {
        return x;
    }
    else {
        return par[x] = find(par[x]);
    }
}

bool same(int x, int y){
    if(find(x) == find(y)){
        return true;
    }
    else{
        return false;
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y){
        return;
    }
    if (rank[x] < rank[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(rank[x] = rank[y]){
            rank[x]++;
        }
    }
    return;
}
int main()
{
    int x, y, t;
    int N = 100;
    int K = 7;
    int T[MAX_K] = {1, 2, 2, 2, 1, 2, 1};
    int X[MAX_K] = {101, 1, 2, 3, 1, 3, 5};
    int Y[MAX_K] = {1, 2, 3, 3, 3, 1, 5};
    int ans = 0;

//    scanf("%d%d", &N, &K);

    init(MAX_N);

    for (int i = 0; i < K; i++){
        //scanf("%d%d%d", &t, &x, &y);
        t = T[i];
        x = X[i] - 1;
        y = Y[i] - 1;
        if (x < 0 || x >= N || y < 0 || y >= N){
            ans++;
            continue;
        }
        if (t == 1){
            if(same(x, y + N) || same(x, y + 2 * N)) {
                ans++;
            }
            else{
                unite(x , y);
                unite(x + N , y + N);
                unite(x + 2 * N , y + 2 * N);
            }
        }
        else{
            if (same(x,y) || same(x, y + 2 * N)) {
                ans++;
            }
            else{
                unite(x , y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    printf("\n%d\n", ans);
    return 0;
}