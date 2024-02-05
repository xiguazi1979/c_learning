#include <cstdio>
#include <map>
#include <string>

using namespace std;

const int MAX_N = 100;  // max number for animals
const int MAX_K = 8;    // number of info to check

int parent[MAX_N * 3];  // parent node of each i-th element, as root, parent[x] == x
int depth[MAX_N * 3];   // tree depth of i-th element's tree

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        depth[i] = 1; // why 0 n book??
    }
}

int find(int x)
{
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }

    if (depth[x] < depth[y]) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
        if (depth[x] == depth[y]) {
            depth[y]++;
        }
    }
}

bool same(int x, int y)
{
    bool ret = true;
    ret = find(x) == find(y);
    return ret;
}

void solve()
{
    int T[MAX_K] = {1, 2, 2, 2, 1, 2, 1, 2};
    int X[MAX_K] = {101, 1, 2, 3, 1, 3, 5, 3};
    int Y[MAX_K] = {1, 2, 3, 3, 3, 1, 5, 1};

    init(MAX_N * 3);

    int answer = 0;
    for (int i = 0; i < MAX_K; i++) {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1; // let animal number starts from 0

        if (x < 0 || x >= MAX_N || y < 0 || y >= MAX_N) {
            answer++;
            printf("\nfind a fault [%d]th.", i);
            continue;
        }

        if (t == 1) {
            //if (same(x, y + MAX_N) || same(x, y + 2 * MAX_N) || same(x + MAX_N, y) || same(x + 2 * MAX_N, y + MAX_N)) {
            if (same(x, y + MAX_N) || same(x, y + 2 * MAX_N)) {
                answer++;
                printf("\nfind a fault [%d]th.", i);
                continue;
            }
            else {
                unite(x, y);
                unite(x + MAX_N, y + MAX_N);
                unite(x + 2 * MAX_N, y + 2 * MAX_N);
            }
        }
        else {
            if (same(x, y) || same(x, y + 2 * MAX_N)) {
                answer++;
                printf("\nfind a fault [%d]th.", i);
                continue;
            }
            else {
                unite(x, y + MAX_N);
                unite(x + MAX_N, y + 2 * MAX_N);
                unite(x + 2 * MAX_N, y);
            }
        }
    }
}
int main()
{
    solve();
    return 0;
}