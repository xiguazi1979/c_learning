#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int N = 3;
int L[3] = {8, 5, 8};

void solve()
{
    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> mQueue;
    for (int i = 0; i < N; i++) {
        mQueue.push(L[i]);
    }
    while (mQueue.size() > 1) {
        int l1 = mQueue.top();
        mQueue.pop();
        int l2 = mQueue.top();
        mQueue.pop();
        ans += (l1 + l2);
        mQueue.push(l1 + l2);
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}