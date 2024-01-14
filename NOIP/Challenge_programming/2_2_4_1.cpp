#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 6, R = 10;
int X[] = {1, 7, 15, 20, 30, 50};

void solve()
{
    sort(X, X + N);

    int i = 0, answer = 0;

    while (i < N) {
        int s = X[i++]; // i: left most point not covered yet

        while (i < N && X[i] <= s + R) {
            i++;
        }

        int p = X[i - 1];
        printf("(%d):[%d], ", i - 1, p);
        answer++;

        while (i < N && X[i] <= p + R) {
            i++;
        }
    }

    printf("\nanswer is %d\n", answer);
}

int main()
{
    solve();
    return 0;
}