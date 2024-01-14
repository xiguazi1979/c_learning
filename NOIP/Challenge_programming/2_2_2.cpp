#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 5;

const int N = 5;
const int S[MAX_N] = {1, 2, 4, 6, 8};   // task start time
const int t[MAX_N] = {3, 5, 7, 9, 10};  // task end time

pair<int, int> itv[MAX_N];

void solve()
{
    int answer = 0, time = 0;

    for (int i = 0; i < N; i++) {
        itv[i].first = t[i];
        itv[i].second = S[i];
    }

    sort(itv, itv + N);

    printf("\n");

    for (int i = 0; i < N; i++) {
        if (time < itv[i].second) {
            answer++;
            printf("%d->%d,", itv[i].second, itv[i].first);
            time = itv[i].first;
        }
    }

    printf("\nanswer is:%d.\n", answer);
}

int main()
{
    solve();
    return 0;
}