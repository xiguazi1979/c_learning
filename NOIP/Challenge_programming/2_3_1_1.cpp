#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4;
int n = MAX_N;
int W = 5;
int w[MAX_N] = {2, 1, 3, 2};
int v[MAX_N] = {3, 2, 4, 2};

// sine i-th, select and get total weight <= j
int rec(int i, int j) {
    int result = 0;

    if (i == n) {
        result = 0;
    }
    else if (j < w[i]) {
        // i-th couldn't be selected already
        result = rec(i + 1, j);
    }
    else {
        int a = rec(i + 1, j);
        int b = rec(i + 1, j - w[i]) + v[i];
        result = max(a, b);
        if (a >= b) {
            printf("[%d], ", i);
        }
        else {
            printf("%d, ", i);
        }
        result = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);

    }

    return result;
}
void solve()
{
    printf("\nresult is %d\n", rec(0, W));
}

int main()
{
    solve();
    return 0;
}