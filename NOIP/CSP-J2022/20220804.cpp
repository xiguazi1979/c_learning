#include <cstdio>
#include <algorithm>

using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6] = {3, 2, 1, 3, 0, 2};
int A = 620;``
void solve()
{
    int answer = 0;
    int total = A;
    for (int i = 5; i >= 0; i--) {
        int x = min(total / V[i], C[i]);
        total = total - x * V[i];
        answer += x;
        printf("V[%d] : %d  ", i, x);
    }
    printf("The answer is %d", answer);
}

int main()
{
    solve();
    return 0;
}