#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
/*
int N = 5;
int L[] = {1, 2, 3, 4, 5};
*/
int N = 3;
int L[] = {8, 5, 8};

void solve()
{
    ll answer = 0;
    priority_queue<int, vector<int>, greater<int>> mQueue;

    for (int i = 0; i < N; i++) {
        mQueue.push(L[i]);
    }
    while (mQueue.size() > 1) {
        int l1, l2;
        l1 = mQueue.top();
        mQueue.pop();
        l2 = mQueue.top();
        mQueue.pop();

        answer += l1 + l2;
        mQueue.push(l1 + l2);
    }

    printf("%lld\n", answer);
}

int main()
{
    solve();
    return 0;
}